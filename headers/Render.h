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
using namespace cv;
using namespace std;
using namespace std;

class Render{
    private:

    public:
        Render(unique_ptr<ifstream> & file);

};

#endif