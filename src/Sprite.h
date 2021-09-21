#pragma once

#include <string>

class Sprite {

private:
	char** asciiArt;
	int height, width;

public:

	explicit Sprite(const std::string& filename);
    virtual ~Sprite();

    char** GetAsciiArt() const;
    int GetHeight() const;
    int GetWidth() const;

};
