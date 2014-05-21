#include "SectorMap.h"
#include "PDcurses/curses.h"

SectorMap::SectorMap(){
	m_XSize = MAP_SIZE_X;
	m_YSize = MAP_SIZE_Y;
	m_Symbol = Symbol('P', COLOR_YELLOW);
}

SectorMap::SectorMap(char symbol, int color, int height){
	m_XSize = MAP_SIZE_X;
	m_YSize = MAP_SIZE_Y;
	m_Symbol = Symbol(symbol, color);
	m_Height = height;
}

SectorMap::~SectorMap(){

}


char SectorMap::getSymbol(){
	return m_Symbol.getSymbol();
}

int SectorMap::getColor(){
	return m_Symbol.getColor();
}

int SectorMap::getHeight(){
	return m_Height;
}

void SectorMap::setHeight(int height){
	m_Height = height;
}

void SectorMap::setSymbol(char letter){
	m_Symbol.setSymbol(letter);
}

void SectorMap::setColor(int color){
	m_Symbol.setColor(color);
}
