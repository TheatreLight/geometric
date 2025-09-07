#ifndef __TOOLSRECTANGLE_H__
#define __TOOLSRECTANGLE_H__

#include "ToolsWindow.h"

class ToolsRectangle : public ToolsWindow {
public:
    explicit ToolsRectangle(HWND parent = nullptr);
    ~ToolsRectangle() = default;
private:
    HWND createWindow(const char* header) override;
    static LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};
#endif // __TOOLSRECTANGLE_H__
