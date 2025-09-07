#ifndef __SQUARE_H__
#define __SQUARE_H__

#include "Rectangle.h"
#include <cmath>

class Square : public RectangleCustom {
public:
    explicit Square(int side, int posX, int posY);
    virtual ~Square() = default;
};
#endif // __SQUARE_H__
