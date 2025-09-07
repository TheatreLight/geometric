#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "IFigure.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

class Triangle : public IFigure {
public:
    explicit Triangle(int sideA, int sideB, int angle, int posX, int posY);
    virtual ~Triangle() = default;
    void paint(HDC hdc) override;
private:
    std::vector<POINT> getPoints();
    int sideA_ = 0;
    int sideB_ = 0;
    int angle_ = 0;
};
#endif // __TRIANGLE_H__
