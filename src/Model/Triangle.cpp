#include "Triangle.h"
#include <vector>

Triangle::Triangle(int sideA, int sideB, int angle, int posX, int posY) :
    IFigure(EFigureType::Triangle, posX, posY)
    , sideA_(sideA)
    , sideB_(sideB)
    , angle_(angle)
{}

void Triangle::paint(HDC hdc)
{
    std::vector<POINT> points = getPoints();
    Polygon(hdc, points.data(), 3);
}

std::vector<POINT> Triangle::getPoints()
{
    double rad = static_cast<double>(angle_) * M_PI / 180.0;
    double x0 = static_cast<double>(posX_);
    double y0 = static_cast<double>(posY_);
    double x1 = x0 + static_cast<double>(sideA_);
    double y1 = y0;
    double x2 = x0 + static_cast<double>(sideB_) * cos(rad);
    double y2 = y0 + static_cast<double>(sideB_) * sin(rad);
    return { {static_cast<LONG>(x0), static_cast<LONG>(y0)},
             {static_cast<LONG>(x1), static_cast<LONG>(y1)},
             {static_cast<LONG>(x2), static_cast<LONG>(y2)} };
}
