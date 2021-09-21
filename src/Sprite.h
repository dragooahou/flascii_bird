#pragma once

class Sprite {

private:
	char** asciiArt;

public:
	char** LoadAsciiFromFile(char* filename);

};
