#include "../headers/Render.h"

Render::Render(unique_ptr<ifstream> & file, ImageSpecs & Specs)
{ 
    try{
        

        this->Specs = Specs;

        if(Specs.mode == Mode::RGB){
        // load the rgb values into 3Bvector
        this->rbgValues.reserve(30000);
            while(getline(*file,line)){
                stringstream ss(line);
                ss >> r >> g >> b;
                this->rbgValues.push_back(Vec3b(b, g, r));
            }
            RenderRGB();
        }
        // else(Specs.mode == Mode::GRAYSCALE){
            
        // }

        




    }catch(...){
        cout<< "Error At pre-Redering"<<endl;
    }

}

void Render::RenderRGB(){
    try{
        int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
        int FPS = 25;
        cv::Size frameSize(this->Specs.width, this->Specs.length );
        cv::VideoWriter videoWriter("output.avi", codec, FPS, frameSize, true); // create VideoWriter object

        if (!videoWriter.isOpened()) {
        // check if video writer was opened successfully
        std::cout << "Could not open the output video file for write." << std::endl;
        return;
        }

        // get the total number of pixels
        int totalPixels = this->rbgValues.size();
        
        int pixelPerImage = (this->Specs.width / 2) * (this->Specs.length / 2) ;

        // number of images
        int totalImages = ceil(totalPixels / pixelPerImage);
        cout<< totalPixels <<endl;
        cout<< pixelPerImage <<endl;
        int i = 0;
        int index = 0;


        while(i <= totalImages){
            
            cv::Mat img(Specs.length, Specs.width, CV_8UC3);
            img.setTo(cv::Scalar(255, 255, 255));

            
            for (int i = 0; i < Specs.length; i += 2) {
                for (int j = 0; j < Specs.width; j += 2) {
                        img.at<cv::Vec3b>(i, j) = img.at<cv::Vec3b>(i, j + 1) = img.at<cv::Vec3b>(i + 1, j) = img.at<cv::Vec3b>(i + 1, j + 1) = this->rbgValues[index];
                        index++;
                }
            }
            videoWriter.write(img);
            // string filename = "out/output" + to_string(i) + ".png";
            // imwrite(filename, img);
            i++;
        }
        cout<< "*********" <<endl;
        videoWriter.release();
}    catch (const std::exception& e) {
        // Handle the exception by printing out the error message
        std::cerr << "Error on line " << __LINE__ << ": " << e.what() << std::endl;
    }
}