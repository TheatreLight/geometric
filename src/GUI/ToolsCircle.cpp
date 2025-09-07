#include "ToolsCircle.h"

ToolsCircle::ToolsCircle(HWND parent)
    : ToolsWindow(parent, (void*)ToolsCircle::WinProc, 250, 250, 180, 180, 250)
{
}

HWND ToolsCircle::createWindow(const char* header)
{
    HWND hwnd = CreateWindowEx(
        WS_EX_TOOLWINDOW,
        CLASS_NAME,
        "Settings",
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
    HWND hLabelRad = CreateWindow(
        "STATIC",
        "Radius",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        80, 20,
        50, 20,
        hwnd,
        (HMENU)0,
        hInstance_,
        nullptr
    );

    HWND hRad = CreateWindow(
        "EDIT",
        "50",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_NUMBER,
        20, 20,
        50, 25,
        hwnd,
        (HMENU)1,
        hInstance_,
        nullptr
    );

    HWND hLabelX = CreateWindow(
        "STATIC",
        "Pos X",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        80, 40,
        50, 20,
        hwnd,
        (HMENU)0,
        hInstance_,
        nullptr
    );

    HWND hXPos = CreateWindow(
        "EDIT",
        "400",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_NUMBER,
        20, 40,
        50, 25,
        hwnd,
        (HMENU)2,
        hInstance_,
        nullptr
    );

    HWND hLabelY = CreateWindow(
        "STATIC",
        "Pos Y",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        80, 60,
        50, 20,
        hwnd,
        (HMENU)0,
        hInstance_,
        nullptr
    );

    HWND hYPos = CreateWindow(
        "EDIT",
        "300",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_NUMBER,
        20, 60,
        50, 25,
        hwnd,
        (HMENU)3,
        hInstance_,
        nullptr
    );

    HWND rndCheck = CreateWindow(
        "BUTTON",
        "Random position",
        WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
        20, 80, 150, 25,
        hwnd,
        (HMENU)4,
        hInstance_,
        nullptr);

    HWND okButt = CreateWindow(
        "BUTTON",
        "OK",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        100, 180, 60, 20,
        hwnd,
        (HMENU)5,
        hInstance_,
        nullptr);

    return hwnd;
}

LRESULT CALLBACK ToolsCircle::WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    ToolsCircle* p_this = reinterpret_cast<ToolsCircle*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    
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
        
        if (id == 5 && notifCode == BN_CLICKED) {
            if (p_this) {
                char buf[128] = {0};
                
                HWND hRad = GetDlgItem(hwnd, 1);
                HWND hXPos = GetDlgItem(hwnd, 2);
                HWND hYPos = GetDlgItem(hwnd, 3);
                HWND hRandom = GetDlgItem(hwnd, 4);
                
                LRESULT isChecked = SendMessage(hRandom, BM_GETCHECK, 0, 0);
                
                if (isChecked == BST_CHECKED) {
                    p_this->params_.xPos = 100 + (rand() % 800);
                    p_this->params_.yPos = 100 + (rand() % 600);
                } else {
                    GetWindowTextA(hXPos, buf, sizeof(buf));
                    int x = atoi(buf);
                    p_this->params_.xPos = (x > 0) ? x : 400;
                    
                    GetWindowTextA(hYPos, buf, sizeof(buf));
                    int y = atoi(buf);
                    p_this->params_.yPos = (y > 0) ? y : 300;
                }
                
                GetWindowTextA(hRad, buf, sizeof(buf));
                int radius = atoi(buf);
                p_this->params_.radius = (radius > 0) ? radius : 50;
                
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

