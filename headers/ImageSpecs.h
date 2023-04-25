#ifndef Img_h
#define Img_h
#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <memory>


enum class Size {
    SMALL,
    MEDIUM,
    LARGE
};

enum class Mode {
    GRAYSCALE,
    COLOUR
};


class ImageSpecs{

    private:
        Size size;
        Mode mode;

    public:
        ImageSpecs(Size size, Mode mode);
        
};
#endif