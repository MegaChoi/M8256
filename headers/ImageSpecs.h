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
    RGB
};


class ImageSpecs{

    private:
        
        void ChangeSize();
    public:
        ImgSize size;
        Mode mode;
        int length;
        int width;

        ImageSpecs() : width(1280), length(720), mode(Mode::GRAYSCALE){}
        ImageSpecs(ImgSize size, Mode mode);
        
};
#endif