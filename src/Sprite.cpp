#include "Sprite.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Sprite::Sprite(const char* filename) {

	ifstream input;
	input.open(filename);
	if (!input.is_open()) throw runtime_error("blabla");
	string nextLine;

	//Initiate height and width of a sprite according to the first line
	input >> width;
	input >> height;

	asciiArt = new char[height*width];

	int i = 0;
	while (input.good()) {
		getline(input, nextLine);
		memcpy(&asciiArt[i * width], nextLine.c_str(), width);
	}

}
