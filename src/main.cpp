#include <iostream>
#include <bitset>
#include <thread>
#include <fstream>
#include <chrono>
#include <string>
#include "../headers/Utils.h"
#include "../headers/ImageSpecs.h"
#include "../headers/Render.h"
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
            unique_ptr<ofstream> outputFile = Utils::WriteFile(argv[2]);

            // generate RBG code file 
            Utils::EncodeRBG(file, outputFile);

            file.reset();
            outputFile.reset();

            // init image size
            ImageSpecs imgSpecs(ImgSize::MEDIUM, Mode::GRAYSCALE);

            unique_ptr<ifstream> rgbFile = Utils::OpenFile(argv[2]);
            // Render 
            Render render(rgbFile, imgSpecs);
                
        }catch(...){

        }
    }
    else{
        cerr  << "Invalid Input" << endl;
    }

    return 0;
} 







