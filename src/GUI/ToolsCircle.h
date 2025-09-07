#ifndef __TOOLSCIRCLE_H__
#define __TOOLSCIRCLE_H__
#include "ToolsWindow.h"
#include <windows.h>

class ToolsCircle : public ToolsWindow {
public:
    explicit ToolsCircle(HWND parent = nullptr);
    ~ToolsCircle() = default;
private:
    HWND createWindow(const char* header) override;
    static LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif // __TOOLSCIRCLE_H__
