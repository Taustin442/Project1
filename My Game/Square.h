#ifndef SQUARE_H
#define SQUARE_H

#include <vector>

#define TILE_FLOOR  0
#define TILE_WALL   1

class Square{
public:
	Square();
	Square(int Terrain);
	void DisplaySymbol();
private:
	char m_Symbol;
	int m_SquareType;
	// vector<Square> map;
};

#endif //SQUARE