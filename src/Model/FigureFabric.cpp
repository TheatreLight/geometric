#include "FigureFabric.h"
#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Square.h"
#include <stdexcept>

std::unique_ptr<IFigure> FigureFabric::makeFigure(EFigureType type, TransferParams tParams)
{
    switch (type) {
    case EFigureType::Circle:
        return std::make_unique<Circle>(tParams.radius, tParams.xPos, tParams.yPos);
    case EFigureType::Triangle:
        return std::make_unique<Triangle>(tParams.sideA, tParams.sideB, tParams.angle, tParams.xPos, tParams.yPos);
    case EFigureType::Rectangle:
        return std::make_unique<RectangleCustom>(tParams.sideA, tParams.sideB, tParams.xPos, tParams.yPos);
    case EFigureType::Square:
        return std::make_unique<Square>(tParams.sideA, tParams.xPos, tParams.yPos);
    default:
        throw std::runtime_error("Unknown figure");
    }
}
