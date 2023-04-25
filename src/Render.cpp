#include "../headers/Render.h"

Render::Render(unique_ptr<ifstream> & file, ImageSpecs & Specs){
    try{

        // load the rgb values into 3Bvector
        this->rbgValues.reserve(30000);

        while(getline(*file,line)){
            stringstream ss(line);
            ss >> r >> g >> b;
            this->rbgValues.push_back(Vec3b(b, g, r));

        }
        // get the total number of pixels
        int totalPixels = this->rbgValues.size();
        
        int pixelPerImage = (Specs.width / 2) * (Specs.length / 2) ;

        // number of images
        int totalImages = ceil(totalPixels / pixelPerImage);
        cout<< totalImages <<endl;
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
            string filename = "out/output" + to_string(i) + ".png";
            imwrite(filename, img);
            i++;
        }


    }catch(...){
        
    }


    
        
}