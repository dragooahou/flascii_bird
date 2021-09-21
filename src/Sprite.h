#pragma once

class Sprite {

private:
	char* asciiArt;
	int height, width;

public:

	explicit Sprite(const char* filename);

    char *GetAsciiArt() const;
    int GetHeight() const;
    int GetWidth() const;

};
