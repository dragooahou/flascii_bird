#pragma once

#include <string>

class Sprite {

private:
	std::string asciiArt;
	int height, width;

public:

	explicit Sprite(const std::string& filename);

    std::string GetAsciiArt() const;
    int GetHeight() const;
    int GetWidth() const;

};
