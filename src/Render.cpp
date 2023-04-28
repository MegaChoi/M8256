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
        }else if(Specs.mode == Mode::GRAYSCALE){
            this->bitValues.reserve(30000);
            
            while(getline(*file,line)){
                this->bitValues.push_back(line);
            }
            RenderGrayscale();
        }

        




    }catch(...){
        cout<< "Error At pre-Redering"<<endl;
    }

}

void Render::RenderRGB(){
    try{
        int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
        int FPS = 25;
        cv::Size frameSize(this->Specs.width, this->Specs.length );
        cv::VideoWriter videoWriter("../out/EncodedRBG.avi", codec, FPS, frameSize, true); // create VideoWriter object

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
        int z = 0;
        int index = 0;

        bool exitLoop = false;
        while(z <= totalImages){
            
            cv::Mat img(Specs.length, Specs.width, CV_8UC3);
            img.setTo(cv::Scalar(255, 255, 255));

            
            for (int i = 0; i < Specs.length && !exitLoop; i += 2) {
                for (int j = 0; j < Specs.width && !exitLoop; j += 2) {
                        img.at<cv::Vec3b>(i, j) = img.at<cv::Vec3b>(i, j + 1) = img.at<cv::Vec3b>(i + 1, j) = img.at<cv::Vec3b>(i + 1, j + 1) = this->rbgValues[index];
                        index++;

                        if(index >= totalPixels){
                            exitLoop = true;
                            break;
                        }
                }
            }
            videoWriter.write(img);
            z++;
        }
        videoWriter.release();
}    catch (const std::exception& e) {
        // Handle the exception by printing out the error message
        std::cerr << "Error on line " << __LINE__ << ": " << e.what() << std::endl;
    }
}

void Render::RenderGrayscale(){
    try{
        int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
        int FPS = 25;
        cv::Size frameSize(this->Specs.width, this->Specs.length );
        cv::VideoWriter videoWriter("../out/EncodedGrayscale.avi", codec, FPS, frameSize, true); // create VideoWriter object

        if (!videoWriter.isOpened()) {
        // check if video writer was opened successfully
        std::cout << "Could not open the output video file for write." << std::endl;
        return;
        }

        // get the total number of pixels
        int totalPixels = this->bitValues.size() * 24;
        int pixelPerImage = (this->Specs.width / 2) * (this->Specs.length / 2) ;

        // number of images
        int totalImages = ceil(totalPixels / pixelPerImage);
        if (totalImages == 0){
            totalImages = 1;
        }
        int z = 0;
        int rowIndex = 0;
        int colIndex = 0;

        cout<< totalPixels <<" " << pixelPerImage << " " << totalImages << endl;
        string bitString = this->bitValues[rowIndex];
        bool exitLoop = false;
        while(z <= totalImages){
            
            Mat img(this->Specs.length, this->Specs.width, CV_8UC3);
            img.setTo(Scalar(255, 255, 255));


            
            for (int i = 0; i < this->Specs.length && !exitLoop; i += 2) {
                for (int j = 0; j < this->Specs.width && !exitLoop; j += 2) {



                    char bit = bitString.at(colIndex);
                    if (bit == '0') {
                        img.at<Vec3b>(i, j) = img.at<Vec3b>(i, j + 1) = img.at<Vec3b>(i + 1, j) = img.at<Vec3b>(i + 1, j + 1) = Vec3b(0,0,0);
                    }
                    else {
                        img.at<Vec3b>(i, j) = img.at<Vec3b>(i, j + 1) = img.at<Vec3b>(i + 1, j) = img.at<Vec3b>(i + 1, j + 1) = Vec3b(255,255,255);
                    }

                    colIndex ++;
                    if (colIndex % 24 == 0) {
                        rowIndex++;
                        if (rowIndex < this->bitValues.size()) {
                            bitString = this->bitValues[rowIndex];
                            colIndex = 0;
                        }
                        else {
                            exitLoop = true;
                            break;
                        }
                    }
                }
            }
            videoWriter.write(img);
            z++;
        }
        videoWriter.release();

}    catch (const std::exception& e) {
        // Handle the exception by printing out the error message
        std::cerr << "Error"<< std::endl;
    }
}