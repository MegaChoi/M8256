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




    
            ifstream wile("output.txt");
            vector<Vec3b> rgb_values;
            rgb_values.reserve(10000); 
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

            cv::Mat img(70, 70, CV_8UC3);
            int index = 0;

            for (int i = 0; i < 70; i++) {
                for (int j = 0; j < 70; j++) {
                        img.at<cv::Vec3b>(i, j) = rgb_values[index];
                        index++;
                        
                }
            }
   

        // Display the image
            imwrite("output.jpg", img);
            cv::waitKey(0);
                
        }catch(...){

        }
    }
    else{
        cerr  << "Invalid Input" << endl;
    }

    // // Read the RGB values from a file
    // ifstream infile("output.txt");
    // vector<Vec3b> rgb_values;
    // int r, g, b;
    // while (infile >> r >> g >> b)
    // {   
    //     rgb_values.push_back(Vec3b(r, g, b));
    // }

    // // Create an image with the same size as the number of RGB values
    // Mat img(rgb_values.size(), 1, CV_8UC3);

    // // Set the color of each pixel to the corresponding RGB value
    // for(int i = 0; i < img.rows; i++)
    // {
    //     img.at<Vec3b>(i, 0) = rgb_values[i];
    // }

    // // Save the image
    // imwrite("output.jpg", img);
    return 0;
} 







