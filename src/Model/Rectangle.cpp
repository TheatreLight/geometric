#include "Rectangle.h"

RectangleCustom::RectangleCustom(int width, int height, int posX, int posY) :
    IFigure(width == height ? EFigureType::Square : EFigureType::Rectangle, posX, posY)
    , width_(width)
    , height_(height)
{
}

void RectangleCustom::paint(HDC hdc)
{
    Rectangle(hdc, 
              posX_, 
              posY_, 
              posX_+width_, 
              posY_+height_);
}
