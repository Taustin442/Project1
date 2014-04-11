#ifndef SECTORMAP_H
#define SECTORMAP_H

#include <vector>
#include "Symbol.h"

const int MAP_SIZE_X = 100;
const int MAP_SIZE_Y = 100;


class SectorMap {
public:
	SectorMap();
	SectorMap(char symbol, int color, int height);
	~SectorMap();
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
	// vector<Square> map;
};


#endif //SECTORMAP