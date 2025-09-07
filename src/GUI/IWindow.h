#ifndef __IWINDOW_H__
#define __IWINDOW_H__
#include <windows.h>

class IWindow {
public:
    IWindow(unsigned width, unsigned height);
    virtual ~IWindow() = default;
    virtual int WINAPI getWindow(const char* header) = 0;
protected:
    virtual HWND createWindow(const char* header) = 0;
    virtual void classRegister(const char* name, void* callback, int background);
    unsigned width_ = 0;
    unsigned height_ = 0;
    HINSTANCE hInstance_ = nullptr;
};

#endif // __IWINDOW_H__
