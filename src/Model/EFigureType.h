#ifndef __EFIGURETYPE_H__
#define __EFIGURETYPE_H__

enum class EFigureType : int 
{
    Undefined = -1,
    Circle = 0,
    Triangle,
    Rectangle,
    Square,
    Pentagon,
    Hexagon,
    Octagon,
    Nonagon,
    Ellipse,
    Rhombus,
    Trapezoid,
    Parallelogram,
    
    End
};

inline const char* figureTypeToString(EFigureType type) {
    switch (type) {
    case EFigureType::Circle: return "Circle";
    case EFigureType::Triangle: return "Triangle";
    case EFigureType::Rectangle: return "Rectangle";
    case EFigureType::Square: return "Square";
    case EFigureType::Pentagon: return "Pentagon";
    case EFigureType::Hexagon: return "Hexagon";
    case EFigureType::Octagon: return "Octagon";
    case EFigureType::Nonagon: return "Nonagon";
    case EFigureType::Ellipse: return "Ellipse";
    case EFigureType::Rhombus: return "Rhombus";
    case EFigureType::Trapezoid: return "Trapezoid";
    case EFigureType::Parallelogram: return "Parallelogram";
    default: return "Undefined";
    }
}

inline EFigureType intToFigureType(int value) {
    if (value < static_cast<int>(EFigureType::End) && value >= static_cast<int>(EFigureType::Circle)) {
        return static_cast<EFigureType>(value);
    }
    return EFigureType::Undefined;
}

#endif // __EFIGURETYPE_H__