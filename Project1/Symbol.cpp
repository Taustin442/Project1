#include "Symbol.h"
#include "PDcurses/curses.h"

Symbol::Symbol() {
	m_Letter = 'P';
	m_Color = COLOR_YELLOW;
}

Symbol::Symbol(char symbol, int color) {
	m_Letter = symbol;
	m_Color = color;
}

Symbol::~Symbol() {
	
}

char Symbol::getSymbol(){
	return m_Letter;
}

int Symbol::getColor(){
	return m_Color;
}

void Symbol::setSymbol(char letter){
	m_Letter = letter;
}

void Symbol::setColor(int color){
	m_Color = color;
}