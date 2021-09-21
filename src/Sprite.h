#pragma once

#include <string>

class Sprite {

private:
	char** asciiArt;
	int height, width;

public:

	explicit Sprite(const std::string& filename);

    char** GetAsciiArt() const;
    int GetHeight() const;
    int GetWidth() const;

};
