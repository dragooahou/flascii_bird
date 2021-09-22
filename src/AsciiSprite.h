#pragma once

#include <string>

#include "Matrix.h"
#include "Vector2.h"

class AsciiSprite {

private:
	Matrix<char> asciiArt;
	int height, width;

public:

    AsciiSprite();
	explicit AsciiSprite(const std::string& filename);
    AsciiSprite(int height, int width);

    ~AsciiSprite();

    const Matrix<char>& GetAsciiArt() const;
    int GetHeight() const;
    int GetWidth() const;

    void SetChar(int x, int y, char c);

    Vector2 GetCenterOffset() const;

};
