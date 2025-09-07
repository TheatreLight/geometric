#ifndef __IFIGURE_H__
#define __IFIGURE_H__

#include "EFigureType.h"
#include <windows.h>

class IFigure {
public:
    IFigure(EFigureType type, int posX, int posY) 
        : type_(type)
        , posX_(posX)
        , posY_(posY)
    {}
    virtual ~IFigure() {};
    EFigureType getType() const { return type_; }
    virtual void paint(HDC hdc) = 0;
    EFigureType type_ = EFigureType::Undefined;
    int posX_ = 0;
    int posY_ = 0;
};

#endif // __IFIGURE_H__