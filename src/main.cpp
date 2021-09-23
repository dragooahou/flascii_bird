#define _WIN32_WINNT 0x0501
#include <windows.h>
#include <wingdi.h>
#include <iostream>

#include "AsciiSprite.h"
#include "utils.h"
#include "AsciiRenderer.h"
#include "InputManager.h"
#include "NYTimer.h"
#include "TextureSprite.h"
#include "Player.h"

#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 80


void InitWindow(int width, int height);
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    NYTimer timer = NYTimer();
    timer.start();

    InitCImg();


    AsciiRenderer<SCREEN_WIDTH, SCREEN_HEIGHT> renderer;

    AsciiSprite* testSprite = new AsciiSprite("assets/test.txt");
    AsciiSprite* testSprite2 = new AsciiSprite("assets/test2.txt");

    InputManager inputManager = InputManager();

    Player player = Player({ 20,20 }, (Graphics(std::vector{ testSprite }, Graphics::Layer::OBJECTS)));

    GameObject gobg;
    gobg.SetPosition({45, 21});
    gobg.SetGfx(Graphics(std::vector{testSprite2}, Graphics::Layer::BACKGROUND));

//    TextureSprite texSprite = TextureSprite("assets/todd.jpg");
//    AsciiSprite toddSprite = texSprite.GetAsciiArt(10, 20);
//    player.SetGfx(Graphics(std::vector{&toddSprite}, Graphics::Layer::OBJECTS));

    // Main loop
    bool isRunning = true;

    while(isRunning) {

        inputManager.ListenToUserInput();
        if (inputManager.getVirtualKeyState(VK_ESCAPE) == InputManager::Input::JUST_PRESSED) {
            isRunning = false;
        }

//        if (inputManager.getVirtualKeyState(VK_SPACE) == InputManager::Input::PRESSED) {
//            texSprite.Rotate(1.f);
//            toddSprite = texSprite.GetAsciiArt(10, 20);
//        }

        player.Update(inputManager, timer);

        if(player.CollideWith(gobg)) {
            player.SetPosition(Vector2(0, 0));
        }

        renderer.Clear();
        renderer.Render(player);
        renderer.Render(gobg);
        renderer.Present();

        Sleep(20);
    }


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

    //Fullscreen
    SendMessage(hwnd_console, WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

    //show window after updating
    ShowWindow(hwnd_console,SW_SHOW);
    
}