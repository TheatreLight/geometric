#include "../Model/FigureFabric.h"
#include "MainWindow.h"
#include "ToolsCircle.h"
#include "ToolsTriangle.h"
#include "ToolsRectangle.h"

#include <stdexcept>
#include <cassert>

MainWindow::MainWindow(unsigned width, unsigned height, int r, int g, int b)
    : IWindow(width, height)
{
    classRegister(CLASS_NAME, this->WinProc, BLACK_BRUSH);
}

MainWindow::~MainWindow()
{
}

int WINAPI MainWindow::getWindow(const char* header) 
{
    auto hwnd = createWindow(header);
    if (hwnd == nullptr) {
        return -1;
    }
    SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)this);
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    MSG msg = {};
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT MainWindow::WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    MainWindow* p_this = (MainWindow*)GetWindowLongPtr(hwnd, GWLP_USERDATA);
    if (p_this == nullptr) {
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    switch(msg) {
        case WM_PAINT: {
            p_this->paint(hwnd);
            return 0;
        }
        case WM_DESTROY: {
            PostQuitMessage(0);
            return 0;
        }
        case WM_COMMAND: {
            p_this->commandHandler(hwnd, wParam);
            return 0;
        }
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

HWND MainWindow::createWindow(const char* header)
{
    HWND hwnd = CreateWindowEx(
        0,
        CLASS_NAME,
        header,
        WS_POPUP,
        CW_USEDEFAULT, CW_USEDEFAULT, width_, height_,
        nullptr, nullptr, hInstance_, nullptr);

    if (!hwnd) return nullptr;

    int buttId = 1;

    HWND clsButt = CreateWindow(
        "BUTTON",
        "CLOSE",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        3, 3, 100, 40,
        hwnd,
        (HMENU)buttId,
        hInstance_,
        nullptr);

    HWND clearButt = CreateWindow(
        "BUTTON",
        "CLEAR",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        3, 46, 100, 40,
        hwnd,
        (HMENU)(++buttId),
        hInstance_,
        nullptr);

    HWND removeLast = CreateWindow(
        "BUTTON",
        "Remove Last",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        3, 89, 100, 40,
        hwnd,
        (HMENU)(++buttId),
        hInstance_,
        nullptr);

    for (int i = 0; i < static_cast<int>(EFigureType::End); ++i) {
        const char* buttName = figureTypeToString(static_cast<EFigureType>(i));
        int place = width_ /static_cast<unsigned>(EFigureType::End);
        int x = 3 + i * place;
        HWND hButton = CreateWindow(
            "BUTTON",
            buttName,
            WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
            x, height_-68, place-6, 40,
            hwnd,
            (HMENU)(++buttId),
            hInstance_,
            nullptr);
    }

    return hwnd;
}

void MainWindow::commandHandler(HWND hwnd, WPARAM wParam)
{
    int id = LOWORD(wParam);
    switch (id) {
    case 1:
        PostQuitMessage(0);
        return;
    case 2:
        figures_.clear();
        InvalidateRect(hwnd, nullptr, TRUE);
        return;
    case 3:
        if (!figures_.empty()) {
            figures_.pop_back();
            InvalidateRect(hwnd, nullptr, TRUE);
        }
        return;
    case 4: {
        toolsWindow_ = std::make_unique<ToolsCircle>(hwnd);
        if (toolsWindow_->ShowModal("Circle Settings")) {
            auto figure = FigureFabric::makeFigure(EFigureType::Circle, toolsWindow_->getParams());
            if (figure) {
                figures_.push_back(std::move(figure));
                InvalidateRect(hwnd, nullptr, TRUE);
            }
        }
        toolsWindow_.reset();
        return;
    }
    case 5: {
        toolsWindow_ = std::make_unique<ToolsTriangle>(hwnd);
        if (toolsWindow_->ShowModal("Triangle Settings")) {
            auto figure = FigureFabric::makeFigure(EFigureType::Triangle, toolsWindow_->getParams());
            if (figure) {
                figures_.push_back(std::move(figure));
                InvalidateRect(hwnd, nullptr, TRUE);
            }
        }
        toolsWindow_.reset();
        return;
    }
    case 6: {
        toolsWindow_ = std::make_unique<ToolsRectangle>(hwnd);
        if (toolsWindow_->ShowModal("Rectangle Settings")) {
            auto figure = FigureFabric::makeFigure(EFigureType::Rectangle, toolsWindow_->getParams());
            if (figure) {
                figures_.push_back(std::move(figure));
                InvalidateRect(hwnd, nullptr, TRUE);
            }
        }
        toolsWindow_.reset();
        return;
    }
    default:
        return;
    }
}

void MainWindow::paint(HWND hwnd)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);
    HPEN hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
    HBRUSH hBrush = static_cast<HBRUSH>(GetStockObject(HOLLOW_BRUSH));
    HPEN hOldPen = static_cast<HPEN>(SelectObject(hdc, hPen));
    HBRUSH hOldBrush = static_cast<HBRUSH>(SelectObject(hdc, hBrush));
    for (const auto& fig : figures_) {
        fig->paint(hdc);
    }
    SelectObject(hdc, hOldPen);
    SelectObject(hdc, hOldBrush);
    DeleteObject(hPen);
    EndPaint(hwnd, &ps);
}
