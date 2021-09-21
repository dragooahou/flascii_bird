#include "Sprite.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char** Sprite::LoadAsciiFromFile(char* filename) {
	char** ascii;
	ifstream input;
	input.open(filename);
	string nextLine;


	while (input.good()) {

		getline(input, nextLine);

	}

	getline(input, nextLine);
	return ascii;
}
