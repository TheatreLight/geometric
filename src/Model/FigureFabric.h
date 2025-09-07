#ifndef __FIGUREFABRIC_H__
#define __FIGUREFABRIC_H__

#include "IFigure.h"
#include "../Common/TransferParams.h"
#include <memory>

class FigureFabric {
public:
    static std::unique_ptr<IFigure> makeFigure(EFigureType type, TransferParams tParams);
};
#endif // __FIGUREFABRIC_H__
