#ifndef TILE_H
#define TILE_H

#include <vector>
#include "Symbol.h"


class Tile {
public:
	Tile();
	Tile(char symbol, int color, int height);
	~Tile();
	void DisplaySymbol();
	char getSymbol();
	int getColor();
	int getHeight();
	void setHeight(int height);
	void setSymbol(char Letter);
	void setColor(int color);

private:
	int m_XSize;
	int m_YSize;
	int m_Height;
	Symbol m_Symbol;
};


#endif //SECTORMAP