#include "ToolsWindow.h"

#include <string>
#include <stdexcept>

ToolsWindow::ToolsWindow(HWND parent, void* callback, unsigned width, unsigned height, int r, int g, int b)
    : IWindow(width, height)
    , parent_(parent)
    , params_{}
    , dialogResult_(false)
{
    classRegister(CLASS_NAME, callback, WHITE_BRUSH);
}

ToolsWindow::~ToolsWindow()
{}

int __stdcall ToolsWindow::getWindow(const char* header)
{
    return ShowModal(header) ? 0 : -1;
}

bool ToolsWindow::ShowModal(const char* header)
{
    auto hwnd = createWindow(header);
    if (!hwnd) {
        DWORD err = GetLastError();
        return false;
    }
    SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)this);
    
    if (parent_) {
        EnableWindow(parent_, FALSE);
    }
    
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);
    
    MSG msg = {};
    BOOL bRet;
    while ((bRet = GetMessage(&msg, nullptr, 0, 0)) != 0) {
        if (bRet == -1) break;

        if (!IsDialogMessage(hwnd, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    
    if (parent_) {
        EnableWindow(parent_, TRUE);
        SetForegroundWindow(parent_);
    }
    
    return dialogResult_;
}
