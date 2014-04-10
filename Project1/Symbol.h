// COLOR_GREEN

#ifndef SYMBOL_H
#define SYMBOL_H



class Symbol {
public:
	Symbol();
	Symbol(char symbol, int color);
	~Symbol();
	char getSymbol();
	int getColor();
	void setSymbol(char Letter);
	void setColor(int color);

private:
	char m_Letter;
	int m_Color;
};


#endif // SYMBOL_H