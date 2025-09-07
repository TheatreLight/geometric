#include "ToolsRectangle.h"

ToolsRectangle::ToolsRectangle(HWND parent)
    : ToolsWindow(parent, (void*)ToolsRectangle::WinProc, 250, 250, 180, 180, 250)
{
}

HWND ToolsRectangle::createWindow(const char* header)
{
    HWND hwnd = CreateWindowEx(
        WS_EX_TOOLWINDOW,
        CLASS_NAME,
        "Rectangle Settings",
        WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT,
        width_, height_,
        parent_,
        nullptr,
        hInstance_,
        nullptr);
    if (!hwnd) {
        return nullptr;
    }

    // --Width field
    HWND hLabelW = CreateWindow(
        "STATIC",
        "Width",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        80, 20,
        50, 20,
        hwnd,
        (HMENU)0,
        hInstance_,
        nullptr
    );

    HWND hWidth = CreateWindow(
        "EDIT",
        "150",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_NUMBER,
        20, 20,
        50, 25,
        hwnd,
        (HMENU)1,
        hInstance_,
        nullptr
    );

    // --Height field
    HWND hLabelH = CreateWindow(
        "STATIC",
        "Height",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        80, 40,
        50, 20,
        hwnd,
        (HMENU)0,
        hInstance_,
        nullptr
    );

    HWND Height = CreateWindow(
        "EDIT",
        "",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
        20, 40,
        50, 25,
        hwnd,
        (HMENU)2,
        hInstance_,
        nullptr
    );

    // --Position X field
    HWND hLabelX = CreateWindow(
        "STATIC",
        "Pos X",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        80, 60,
        50, 20,
        hwnd,
        (HMENU)0,
        hInstance_,
        nullptr
    );

    HWND hXPos = CreateWindow(
        "EDIT",
        "",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
        20, 60,
        50, 25,
        hwnd,
        (HMENU)3,
        hInstance_,
        nullptr
    );

    // --Position Y field
    HWND hLabelY = CreateWindow(
        "STATIC",
        "Pos Y",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        80, 80,
        50, 20,
        hwnd,
        (HMENU)0,
        hInstance_,
        nullptr
    );

    HWND hYPos = CreateWindow(
        "EDIT",
        "",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT,
        20, 80,
        50, 25,
        hwnd,
        (HMENU)4,
        hInstance_,
        nullptr
    );

    HWND rndCheck = CreateWindow(
        "BUTTON",
        "Random position",
        WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
        20, 100, 150, 25,
        hwnd,
        (HMENU)5,
        hInstance_,
        nullptr);

    HWND okButt = CreateWindow(
        "BUTTON",
        "OK",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        100, 180, 60, 20,
        hwnd,
        (HMENU)6,
        hInstance_,
        nullptr);

    return hwnd;
}

LRESULT ToolsRectangle::WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    ToolsRectangle* p_this = reinterpret_cast<ToolsRectangle*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    
    switch (msg) {
    case WM_CLOSE:
        if (p_this) {
            p_this->dialogResult_ = false;
        }
        DestroyWindow(hwnd);
        return 0;
        
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
        
    case WM_COMMAND: {
        int id = LOWORD(wParam);
        int notifCode = HIWORD(wParam);
        
        if (id == 6 && notifCode == BN_CLICKED) {
            if (p_this) {
                char buffer[128] = {0};
                HWND hRandom = GetDlgItem(hwnd, 5);
                
                LRESULT isChecked = SendMessage(hRandom, BM_GETCHECK, 0, 0);
                
                GetWindowText(GetDlgItem(hwnd, 1), buffer, sizeof(buffer));
                int width = atoi(buffer);
                p_this->params_.sideA = (width > 0) ? width : 150;
                
                GetWindowText(GetDlgItem(hwnd, 2), buffer, sizeof(buffer));
                int height = atoi(buffer);
                p_this->params_.sideB = (height > 0) ? height : 100;
                
                if (isChecked == BST_CHECKED) {
                    p_this->params_.xPos = 100 + (rand() % 800);
                    p_this->params_.yPos = 100 + (rand() % 600);
                } else {
                    GetWindowText(GetDlgItem(hwnd, 3), buffer, sizeof(buffer));
                    int x = atoi(buffer);
                    p_this->params_.xPos = (x > 0) ? x : 400;
                    
                    GetWindowText(GetDlgItem(hwnd, 4), buffer, sizeof(buffer));
                    int y = atoi(buffer);
                    p_this->params_.yPos = (y > 0) ? y : 300;
                }
                
                p_this->dialogResult_ = true;
            }
            DestroyWindow(hwnd);
        }
        return 0;
    }
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}
