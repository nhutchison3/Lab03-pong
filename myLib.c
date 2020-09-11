#include "myLib.h"

unsigned short *videoBuffer = (unsigned short *)0x6000000;

void setPixel(int col, int row, unsigned short color) {
	videoBuffer[OFFSET(col, row, SCREENWIDTH)] = color;
}

void drawRect(int col, int row, int width, int height, unsigned short color) {
	for(int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            setPixel(col+c, row+r, color);
        }
	}
}

void fillScreen(unsigned short color) {
	for(int i = 0; i < SCREENWIDTH * SCREENHEIGHT; i++) {
        videoBuffer[i] = color;
    }
}

void waitForVBlank() {
	while(SCANLINECOUNTER > 160);
	while(SCANLINECOUNTER < 160);
}

int collision(int colA, int rowA, int widthA, int heightA, int colB, int rowB, int widthB, int heightB) {
    return colA < colB + widthB - 1 && colA + widthA - 1 > colB
        && rowA < rowB + heightB - 1 && rowA + heightA - 1 > rowB;
}
