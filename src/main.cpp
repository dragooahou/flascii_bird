#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <iostream>

#include "utils.h"

#define SCREEN_WIDTH 120
#define SCREEN_HEIGHT 40


void InitWindow(int width, int height);


int main() {


    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT);


    std::cout << "Test string" << std::endl;


    char c;
    std::cin >> c;


    return 0;
}


void InitWindow(int width, int height) {

    SetLastError(NO_ERROR);

    LONG_PTR new_style = (WS_OVERLAPPED     |
                          WS_CAPTION        |
                          WS_SYSMENU        |
                          WS_MINIMIZEBOX    );

    HWND hwnd_console = GetConsoleWindow();
    HANDLE hwnd_std = GetStdHandle(STD_OUTPUT_HANDLE);

    SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = height - 1;
    Rect.Right = width - 1;

    COORD screenSize;
    screenSize.X = width;
    screenSize.Y = height;

    // Clear the style of the window
    SetWindowLongPtr(hwnd_console,GWL_STYLE, 0);

    // Set the character buffer size
    if(!SetConsoleScreenBufferSize(hwnd_std, screenSize)) {
        std::cout << "SetConsoleScreenBufferSize() error:  " << utils::GetLastErrorAsString() << std::endl;
    }

    // Size the window buffer size
    if(!SetConsoleWindowInfo(hwnd_std, true, &Rect)) {
        std::cout << "SetConsoleWindowInfo() error:  " << utils::GetLastErrorAsString() << std::endl;
    }

    // Put the wanted style
    SetWindowLongPtr(hwnd_console,GWL_STYLE, new_style);

    //show window after updating
    ShowWindow(hwnd_console,SW_SHOW);
}