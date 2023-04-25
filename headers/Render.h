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
        string line;
        int r, g, b;
    public:
        Render(unique_ptr<ifstream> & file, ImageSpecs & Specs);

};

#endif