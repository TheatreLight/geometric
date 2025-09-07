#ifndef __TOOLSTRIANGLE_H__
#define __TOOLSTRIANGLE_H__
#include "ToolsWindow.h"
#include <windows.h>

class ToolsTriangle : public ToolsWindow {
public:
    explicit ToolsTriangle(HWND parent = nullptr);
    ~ToolsTriangle() = default;
private:
    HWND createWindow(const char* header) override;
    static LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif // __TOOLSTRIANGLE_H__
