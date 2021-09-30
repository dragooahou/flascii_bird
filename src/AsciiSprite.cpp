#include "AsciiSprite.h"

#include <iostream>
#include <fstream>

using namespace std;

AsciiSprite::AsciiSprite(const string& filename) {

	ifstream input;
	input.open(filename);
	if (!input.is_open()) throw runtime_error("Couldn't open file");
	string nextLine = "";

	//Initiate height and width of a sprite according to the first line
	input >> width;
	input >> height;
	string asciiTab[143];
	getline(input, nextLine);

	int i = 0;
	while (!getline(input, nextLine).fail()) {
		asciiTab[i] = nextLine;
		i++;
	}

	asciiArt = Matrix<char>(height, width);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			asciiArt(i, j) = asciiTab[i][j];
		}
	}

}

AsciiSprite::AsciiSprite(int height, int width) : height(height), width(width) {

    asciiArt = Matrix<char>(height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            asciiArt(i, j) = ' ';
        }
    }

}

AsciiSprite::AsciiSprite(const Matrix<char> &matrix) : asciiArt(matrix), height(matrix.GetHeight()), width(matrix.GetWidth()) {
	
}

const Matrix<char>& AsciiSprite::GetAsciiArt() const {
    return asciiArt;
}

int AsciiSprite::GetHeight() const {
    return height;
}

int AsciiSprite::GetWidth() const {
    return width;
}

AsciiSprite::~AsciiSprite() {

}

void AsciiSprite::SetChar(int x, int y, char c) {
    asciiArt[y][x] = c;
}

AsciiSprite::AsciiSprite() : asciiArt(), height(asciiArt.GetHeight()), width(asciiArt.GetWidth()) {

}

Vector2 AsciiSprite::GetCenterOffset() const {
    return Vector2(width/2.f, height/2.f);
}
