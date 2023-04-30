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

void Menu();

int main(int argc, char *argv[]) {

    
    string arg1,arg2,arg3;
    cout<< "_______________________________________________________" <<endl;
    cout<< "                        Welcome                        " <<endl;
    

    while(!cin.eof()){
        Menu();
        if (Utils::ReadInput(arg1,arg2,arg3)){
            try{


            
            // defind input path
            string inputLocation = "../resources/" + arg1;
            unique_ptr<ifstream> file = Utils::OpenFile(inputLocation);

            // defind output path
            unique_ptr<ofstream> outputFile = Utils::WriteFile("../out/output.txt");

            Mode mode; 
            ImgSize size;

            

            if(arg2 == "RGB"){
                // generate RBG code file 
                Utils::EncodeRBG(file, outputFile);
                mode = Mode::RGB;
            }
            else if (arg2 == "GRAYSCALE"){
                // generate Grayscale code file
                Utils::EncodeGrayscale(file, outputFile);
                mode = Mode::GRAYSCALE;
            }
            else{
                cerr  << "Invalid Video Mode" << endl;
                return 0;
            }

            if(arg3 == "SMALL"){
                size = ImgSize::SMALL;
            } else if (arg3 == "MEDIUM"){
                size = ImgSize::MEDIUM;
            } else if (arg3 == "LARGE"){
                size = ImgSize::LARGE;
            }else{
                cerr  << "Invalid Video Size" << endl;
                return 0;
            }


            cout << endl; 
            cout << "File: " << arg1 << endl; 
            cout << "Mode: " << arg2 << endl; 
            cout << "Size: " << arg3 << endl; 
            cout << endl; 
            // reset file opnener pointers
            file.reset();
            outputFile.reset();

            // init image size
            ImageSpecs imgSpecs(size, mode);

            unique_ptr<ifstream> rgbFile = Utils::OpenFile("../out/output.txt");
            // Render 
            Render render(rgbFile, imgSpecs);
                
            }catch(...){}
        }
        else{
            cerr  << "Invalid Input - 3 arguments required <filename> <video mode> <video size>" << endl;
        }
    }
    return 0;
}

        
    


void Menu(){
    cout<< "_______________________________________________________" <<endl;
    cout<<endl;
    cout<< "> To encode your file, follow the command below        " <<endl;
    cout<< ">     <input file> <RBG/GRAYSCALE> <output size>       " <<endl;
    cout<<endl;
    cout<< "> <input file>    : your file name in resources folder " <<endl;
    cout<< "> <RBG/GRAYSCALE> : output mode RGB or GRAYSCALE       " <<endl;
    cout<< "> <output size>   : the size of the output video       " <<endl;
    cout<< "                  > SMALL: 360p  MEDIUM: 720p LARGE: 1080p    " <<endl;
    cout<< "> ctrl-c to quit       " <<endl;
    cout<<endl;
    cout<< "> Enter your commands here: ";
}





