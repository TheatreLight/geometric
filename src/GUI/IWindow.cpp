#include "IWindow.h"

#include <stdexcept>

IWindow::IWindow(unsigned width, unsigned height)
    : width_(width)
    , height_(height)
    , hInstance_(GetModuleHandle(NULL))
{
}

void IWindow::classRegister(const char* name, void* callback, int background)
{
    UnregisterClass(name, hInstance_);
    
    WNDCLASS wc = {};
    wc.lpfnWndProc = reinterpret_cast<WNDPROC>(callback);
    wc.hInstance = hInstance_;
    wc.hbrBackground = static_cast<HBRUSH>(GetStockObject(background));
    wc.lpszClassName = name;
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    
    if (!RegisterClass(&wc)) {
        DWORD error = GetLastError();
        if (error != ERROR_CLASS_ALREADY_EXISTS) {
            throw std::runtime_error("Can't register window class");
        }
    }
}

