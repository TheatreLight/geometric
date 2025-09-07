#ifndef __TOOLSWINDOW_H__
#define __TOOLSWINDOW_H__

#include "IWindow.h"
#include "../Common/TransferParams.h"
#include <windows.h>

class ToolsWindow : public IWindow {
public:
    ToolsWindow(HWND parent = nullptr, void* callback = nullptr, unsigned width = 200, unsigned height = 600, int r = 200, int g = 200, int b = 200);
    ~ToolsWindow();
    int WINAPI getWindow(const char* header) override;
    TransferParams& getParams() { return params_; }
    bool ShowModal(const char* header);
protected:
    virtual HWND createWindow(const char* header) override { return nullptr; };
    static constexpr char CLASS_NAME[] = "ToolsWindow";
    HWND parent_ = nullptr;
    TransferParams params_{};
    bool dialogResult_ = false;
};

#endif // __TOOLSWINDOW_H__
