#ifndef Img_h
#define Img_h
#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <memory>


enum class ImgSize {
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
        ImgSize size;
        Mode mode;
        void ChangeSize();
    public:
        int length;
        int width;
        ImageSpecs(ImgSize size, Mode mode);
        
};
#endif