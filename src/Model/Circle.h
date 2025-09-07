#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "IFigure.h"

#define _USE_MATH_DEFINES
#include <cmath>

class Circle : public IFigure {
public:
    explicit Circle(int radius, int posX, int posY);
    virtual ~Circle() = default;
    void paint(HDC hdc) override;
private:
    double radius_ = 0.0;
};

#endif // __CIRCLE_H__
