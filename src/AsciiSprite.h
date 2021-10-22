#pragma once

#include <windows.h>
#include <string>

#include "Matrix.h"
#include "Vector2.h"

class AsciiSprite {

private:
	Matrix<CHAR_INFO> asciiArt;
	int height, width;

public:

    using Color = uint8_t;

    static constexpr Color FG_RED = FOREGROUND_RED;
    static constexpr Color FG_BLUE = FOREGROUND_BLUE;
    static constexpr Color FG_GREEN = FOREGROUND_GREEN;
    static constexpr Color FG_LIGHTRED = FOREGROUND_RED | FOREGROUND_INTENSITY;
    static constexpr Color FG_LIGHTBLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    static constexpr Color FG_LIGHTGREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    static constexpr Color FG_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN;
    static constexpr Color FG_MAGENTA = FOREGROUND_BLUE | FOREGROUND_RED;
    static constexpr Color FG_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE;
    static constexpr Color FG_LIGHTYELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
    static constexpr Color FG_LIGHTMAGENTA = FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY;
    static constexpr Color FG_LIGHTCYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
    static constexpr Color FG_BLACK = 0;
    static constexpr Color FG_WHITE =  FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

    static constexpr Color BG_RED = BACKGROUND_RED;
    static constexpr Color BG_BLUE = BACKGROUND_BLUE;
    static constexpr Color BG_GREEN = BACKGROUND_GREEN;
    static constexpr Color BG_LIGHTRED = BACKGROUND_RED | BACKGROUND_INTENSITY;
    static constexpr Color BG_LIGHTBLUE = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
    static constexpr Color BG_LIGHTGREEN = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
    static constexpr Color BG_YELLOW = BACKGROUND_RED | BACKGROUND_GREEN;
    static constexpr Color BG_MAGENTA = BACKGROUND_BLUE | BACKGROUND_RED;
    static constexpr Color BG_CYAN = BACKGROUND_GREEN | BACKGROUND_BLUE;
    static constexpr Color BG_LIGHTYELLOW = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
    static constexpr Color BG_LIGHTMAGENTA = BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_INTENSITY;
    static constexpr Color BG_LIGHTCYAN = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
    static constexpr Color BG_BLACK = 0;
    static constexpr Color BG_WHITE =  BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;

    AsciiSprite();
    AsciiSprite(const Matrix<CHAR_INFO> &matrix);
	explicit AsciiSprite(const std::string& filename);
    AsciiSprite(int height, int width);

    ~AsciiSprite();

    const Matrix<CHAR_INFO>& GetAsciiArt() const;
    int GetHeight() const;
    int GetWidth() const;

    void SetChar(int x, int y, char c);

    Vector2 GetCenterOffset() const;

};
