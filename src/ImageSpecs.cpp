#include "../headers/ImageSpecs.h"

ImageSpecs::ImageSpecs(ImgSize size, Mode mode){
    this->size = size;
    this->mode = mode;
    ChangeSize();
}

void ImageSpecs::ChangeSize(){
    switch (this->size)
    {
    case ImgSize::SMALL:
        this->length = 360;
        this->width = 640;
        break;
    case ImgSize::MEDIUM:
        this->length = 720;
        this->width = 1280;
        break;
    case ImgSize::LARGE:
        this->length = 1080;
        this->width = 1920;
        break;
    default:
        break;
    }
}