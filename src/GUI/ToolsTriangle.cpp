#include "ToolsTriangle.h"

ToolsTriangle::ToolsTriangle(HWND parent)
    : ToolsWindow(parent, (void*)ToolsTriangle::WinProc, 250, 250, 180, 180, 250)
{
}

HWND ToolsTriangle::createWindow(const char* header)
{
    HWND hwnd = CreateWindowEx(
        WS_EX_TOOLWINDOW,
        CLASS_NAME,
        "Triangle Settings",
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
    // --Angle field
    HWND hLabelAngle = CreateWindow(
        "STATIC",
        "Angle",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        80, 20,
        50, 20,
        hwnd,
        (HMENU)0,
        hInstance_,
        nullptr
    );

    HWND hAngle = CreateWindow(
        "EDIT",
        "90",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT | ES_NUMBER,
        20, 20,
        50, 25,
        hwnd,
        (HMENU)1,
        hInstance_,
        nullptr
    );

    // --Side A field
    HWND hLabelA = CreateWindow(
        "STATIC",
        "Side A",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        80, 40,
        50, 20,
        hwnd,
        (HMENU)0,
        hInstance_,
        nullptr
    );

    HWND hSideA = CreateWindow(
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

    // --Side B field
    HWND hLabelB = CreateWindow(
        "STATIC",
        "Side B",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        80, 60,
        50, 20,
        hwnd,
        (HMENU)0,
        hInstance_,
        nullptr
    );

    HWND hSideB = CreateWindow(
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

    // --Position X field
    HWND hLabelX = CreateWindow(
        "STATIC",
        "Pos X",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        80, 80,
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
        20, 80,
        50, 25,
        hwnd,
        (HMENU)4,
        hInstance_,
        nullptr
    );

    // --Position Y field
    HWND hLabelY = CreateWindow(
        "STATIC",
        "Pos Y",
        WS_CHILD | WS_VISIBLE | SS_CENTER,
        80, 100,
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
        20, 100,
        50, 25,
        hwnd,
        (HMENU)5,
        hInstance_,
        nullptr
    );

    HWND rndCheck = CreateWindow(
        "BUTTON",
        "Random position",
        WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
        20, 120, 150, 25,
        hwnd,
        (HMENU)6,
        hInstance_,
        nullptr);

    HWND okButt = CreateWindow(
        "BUTTON",
        "OK",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        100, 180, 60, 20,
        hwnd,
        (HMENU)7,
        hInstance_,
        nullptr);

    return hwnd;
}

LRESULT ToolsTriangle::WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    ToolsTriangle* p_this = reinterpret_cast<ToolsTriangle*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    
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
        
        if (id == 7 && notifCode == BN_CLICKED) {
            if (p_this) {
                char buffer[128] = {0};
                HWND hRandom = GetDlgItem(hwnd, 6);
                
                LRESULT isChecked = SendMessage(hRandom, BM_GETCHECK, 0, 0);
                
                GetWindowText(GetDlgItem(hwnd, 1), buffer, sizeof(buffer));
                int angle = atoi(buffer);
                p_this->params_.angle = (angle >= 0 && angle <= 360) ? angle : 90;
                
                GetWindowText(GetDlgItem(hwnd, 2), buffer, sizeof(buffer));
                int sideA = atoi(buffer);
                p_this->params_.sideA = (sideA > 0) ? sideA : 100;
                
                GetWindowText(GetDlgItem(hwnd, 3), buffer, sizeof(buffer));
                int sideB = atoi(buffer);
                p_this->params_.sideB = (sideB > 0) ? sideB : 100;
                
                if (isChecked == BST_CHECKED) {
                    p_this->params_.xPos = 100 + (rand() % 800);
                    p_this->params_.yPos = 100 + (rand() % 600);
                } else {
                    GetWindowText(GetDlgItem(hwnd, 4), buffer, sizeof(buffer));
                    int x = atoi(buffer);
                    p_this->params_.xPos = (x > 0) ? x : 400;
                    
                    GetWindowText(GetDlgItem(hwnd, 5), buffer, sizeof(buffer));
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
