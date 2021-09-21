#include "Sprite.h"

#include <iostream>
#include <fstream>

using namespace std;

Sprite::Sprite(const string& filename) {

	ifstream input;
	asciiArt = "";
	input.open(filename);
	if (!input.is_open()) throw runtime_error("Couldn't open file");
	string nextLine = "";

	//Initiate height and width of a sprite according to the first line
	input >> width;
	input >> height;
	getline(input, nextLine);

	while (!getline(input, nextLine).fail()) {
		asciiArt += nextLine;
	}
}

string Sprite::GetAsciiArt() const {
    return asciiArt;
}

int Sprite::GetHeight() const {
    return height;
}

int Sprite::GetWidth() const {
    return width;
}