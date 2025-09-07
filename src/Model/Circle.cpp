#include "Circle.h"
#include "windows.h"

Circle::Circle(int radius, int posX, int posY) 
    : IFigure(EFigureType::Circle, posX, posY)
    , radius_(radius) 
{}

void Circle::paint(HDC hdc)
{
    Ellipse(hdc, 
            posX_-radius_, 
            posY_ - radius_,
            posX_ + radius_,
            posY_ + radius_);
}
