#ifndef Render_h
#define Render_h
#include <iostream>
#include <bitset>
#include <thread>
#include <fstream>
#include <chrono>
#include <string>
#include <opencv2/opencv.hpp> 
#include <unistd.h>
#include "ImageSpecs.h"
#include <cmath>
using namespace cv;
using namespace std;
using namespace std;

class Render{
    private:
        vector<Vec3b> rbgValues;
        vector<string> bitValues;
        string line;
        int r, g, b;
        ImageSpecs Specs; 

        // video setting 


        void RenderGrayscale();
        void RenderRGB();
        void EncodeVideo();
        
    public:
        Render(unique_ptr<ifstream> & file, ImageSpecs & Specs);

};

#endif