#ifndef __MAINWINDOW_H__
#define __MAINWINDOW_H__

#include "IWindow.h"
#include "ToolsWindow.h"

#include <memory>
#include <vector>
#include <windows.h>

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600

class IFigure;

class MainWindow : public IWindow {
public:
    MainWindow(unsigned width = DEFAULT_WIDTH, unsigned height = DEFAULT_HEIGHT, int r = 0, int g = 0, int b = 0);
    ~MainWindow();
    int WINAPI getWindow(const char* header) override;
private:
    static LRESULT CALLBACK WinProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);
    HWND createWindow(const char* header) override;
    void commandHandler(HWND hwnd, WPARAM wParam);
    void paint(HWND hwnd);
    static constexpr char CLASS_NAME[] = "MainWindow";

    std::unique_ptr<ToolsWindow> toolsWindow_;
    std::vector<std::unique_ptr<IFigure>> figures_;
};
#endif // __MAINWINDOW_H__
