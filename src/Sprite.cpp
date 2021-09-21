#include "Sprite.h"

#include <iostream>
#include <fstream>

using namespace std;

Sprite::Sprite(const string& filename) {

	ifstream input;
	string tempAscii = "";
	input.open(filename);
	if (!input.is_open()) throw runtime_error("Couldn't open file");
	string nextLine = "";

	//Initiate height and width of a sprite according to the first line
	input >> width;
	input >> height;
	getline(input, nextLine);

	while (!getline(input, nextLine).fail()) {
		tempAscii += nextLine;
	}

	asciiArt = new char* [height];
	for (int i = 0; i < height; i++) {
		asciiArt[i] = new char[width];
		for (int j = 0; j < width; j++) {
			asciiArt[i][j] = tempAscii[i * width + j];
		}
	}

}

char** Sprite::GetAsciiArt() const {
    return asciiArt;
}

int Sprite::GetHeight() const {
    return height;
}

int Sprite::GetWidth() const {
    return width;
}

Sprite::~Sprite() {
    for (int i = 0; i < height; i++) {
        delete asciiArt[i];
    }
    delete asciiArt;
}
