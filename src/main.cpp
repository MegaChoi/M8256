#include <iostream>
#include <bitset>
#include <thread>
#include <fstream>
#include <chrono>
#include <string>
#include "../headers/Utils.h"
#include <opencv2/opencv.hpp> 
#include <unistd.h>
using namespace cv;
using namespace std;
int main(int argc, char *argv[]) {
    
    cout<< "./program <inputfile> <outputfile>" << endl;
    // exactly 3 arguments needed, 2 for input and output file
    if (argc == 3) {
        try{
            unique_ptr<ifstream> file = Utils::OpenFile(argv[1]);
            unique_ptr<ofstream> binaryFile = Utils::WriteFile(argv[2]);

            // generate RBG code file 
            Utils::EncodeRBG(file, binaryFile);

            file.reset();
            binaryFile.reset();




    
            ifstream wile(argv[2]);
            vector<Vec3b> rgb_values;
            rgb_values.reserve(30000); 
            std::string line;

            while (std::getline(wile, line)) {
                // Extract the RGB values from the line
                std::stringstream ss(line);
                int r, g, b;
                
                // cout<< r << g << b <<endl;
                // sleep(1);
                ss >> r >> g >> b;

                // Add the RGB values to the vector
                rgb_values.push_back(Vec3b(b, g, r));
            }
            cout<<rgb_values.size()<<endl;
            
            cv::Mat img(360, 640, CV_8UC3);
            img.setTo(cv::Scalar(255, 255, 255));
            int index = 0;

            for (int i = 0; i < 360; i += 2) {
                for (int j = 0; j < 640; j += 2) {
                        
                        img.at<cv::Vec3b>(i, j) = img.at<cv::Vec3b>(i, j + 1) = img.at<cv::Vec3b>(i + 1, j) = img.at<cv::Vec3b>(i + 1, j + 1) = rgb_values[index];
                        index++;
                }
            }
   

            // Display the image
            imwrite("out/output.png", img);
                
        }catch(...){

        }
    }
    else{
        cerr  << "Invalid Input" << endl;
    }

    return 0;
} 







