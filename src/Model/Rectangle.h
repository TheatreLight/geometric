#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "IFigure.h"
#include <cmath>

class RectangleCustom : public IFigure {
public:
    explicit RectangleCustom(int width, int height, int posX, int posY);
    virtual ~RectangleCustom() = default;
    void paint(HDC hdc) override;
private:
    int width_ = 0;
    int height_ = 0;
};
#endif // __RECTANGLE_H__