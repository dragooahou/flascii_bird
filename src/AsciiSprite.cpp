#include "AsciiSprite.h"

#include <iostream>
#include <fstream>
#include <map>

using namespace std;

#define STR_TO_COLOR_WITH_PREFIX(prefix)                                \
    std::map<std::string, AsciiSprite::Color> strToColor##prefix = {    \
                                                                        \
            {"red", AsciiSprite::prefix##_RED},                         \
            {"blue", AsciiSprite::prefix##_BLUE},                       \
            {"green", AsciiSprite::prefix##_GREEN},                     \
                                                                        \
            {"lightred", AsciiSprite::prefix##_LIGHTRED},               \
            {"lightgreen", AsciiSprite::prefix##_LIGHTGREEN},           \
            {"lightblue", AsciiSprite::prefix##_LIGHTBLUE},             \
                                                                        \
            {"yellow", AsciiSprite::prefix##_YELLOW},                   \
            {"magenta", AsciiSprite::prefix##_MAGENTA},                 \
            {"cyan", AsciiSprite::prefix##_CYAN},                       \
                                                                        \
            {"lightyellow", AsciiSprite::prefix##_LIGHTYELLOW},         \
            {"lightmagenta", AsciiSprite::prefix##_LIGHTMAGENTA},       \
            {"lightcyan", AsciiSprite::prefix##_LIGHTCYAN},             \
                                                                        \
            {"black", AsciiSprite::prefix##_BLACK},                     \
            {"gray", AsciiSprite::prefix##_GRAY},                       \
            {"white", AsciiSprite::prefix##_WHITE},                     \
    };                                                                  \

STR_TO_COLOR_WITH_PREFIX(FG)
STR_TO_COLOR_WITH_PREFIX(BG)

AsciiSprite::AsciiSprite(const string& filename) {

    std::cout << "loading " << filename << std::endl;

	ifstream input;
	input.open(filename);
	if (!input.is_open()) throw runtime_error("Couldn't open file");
	string nextLine = "";

	//Initiate height and width of a sprite according to the first line
	input >> width;
	input >> height;
	getline(input, nextLine);

    // Get the ascii data and fill the matrix
    asciiArt = Matrix<CHAR_INFO>(height, width);
    for (int i = 0; i < height; i++) {

        if(!input.good()) {
            return;
        }

        getline(input, nextLine);

        for (int j = 0; j < width; j++) {
            CHAR c = j < nextLine.size() ? nextLine[j] : ' ';
            asciiArt(i, j).Char.AsciiChar = c;
            asciiArt(i, j).Attributes = FG_WHITE | BG_BLACK;
        }

    }

    if(!input.good()) {
        return;
    }

    // The number of color
    int colorCount = 0;
    input >> colorCount;
    getline(input, nextLine);

    std::map<uint8_t, std::string> colors;

    // Get each color
    for(int i = 0; i < colorCount; ++i) {

        int colorID;
        std::string colorName;

        input >> colorID;
        input >> colorName;
        colors[colorID] = colorName;

        getline(input, nextLine);
    }

    // The empty line
    getline(input, nextLine);

    // Foreground
    for (int i = 0; i < height; i++) {

        if(!input.good()) {
            return;
        }

        getline(input, nextLine);
        for (int j = 0; j < nextLine.size(); j++) {

            uint8_t colorID = nextLine[j] - '0';
            const std::string& colorName = colors[colorID];
            auto color = strToColorFG[colorName];

            asciiArt(i, j).Attributes = color;

        }


    }

    // The empty line
    getline(input, nextLine);

    // Background
    for (int i = 0; i < height; i++) {

        if(!input.good()) {
            return;
        }

        getline(input, nextLine);
        for (int j = 0; j < nextLine.size(); j++) {

            uint8_t colorID = nextLine[j] - '0';
            const std::string& colorName = colors[colorID];
            auto color = strToColorBG[colorName];

            asciiArt(i, j).Attributes |= color;

        }

    }


}

AsciiSprite::AsciiSprite(int height, int width) : height(height), width(width) {

    asciiArt = Matrix<CHAR_INFO>(height, width);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            asciiArt(i, j).Char.AsciiChar = ' ';
            asciiArt(i, j).Attributes = FG_WHITE | BG_BLACK;
        }
    }

}

AsciiSprite::AsciiSprite(const Matrix<CHAR_INFO> &matrix) : asciiArt(matrix), height(matrix.GetHeight()), width(matrix.GetWidth()) {
	
}

const Matrix<CHAR_INFO>& AsciiSprite::GetAsciiArt() const {
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
    asciiArt[y][x].Char.AsciiChar = c;
}

AsciiSprite::AsciiSprite() : asciiArt(), height(asciiArt.GetHeight()), width(asciiArt.GetWidth()) {

}

Vector2 AsciiSprite::GetCenterOffset() const {
    return Vector2(width/2.f, height/2.f);
}
