

/* This program shows how to pick up the scan codes from a keyboard */
/* These define the scan codes(IBM) for the keys. All numbers are in decimal.*/
#define PAGE_UP     73
#define HOME        71
#define END         79
#define PAGE_DOWN   81
#define UP_ARROW    72
#define LEFT_ARROW  75
#define DOWN_ARROW  80
#define RIGHT_ARROW 77
#define F1          59
#define F2          60
#define F3          61
#define F4          62
#define F5          63
#define F6          64
#define F7          65
#define F8          66
#define F9          67
#define F10         68
#define F11			133
#define F12			134
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

string getInput()
{
	int KeyStroke;
	string x;


		KeyStroke = _getch();
		
		if ((KeyStroke == 0) || (KeyStroke == 224))
		{
			KeyStroke = _getch(); // Even though there are 2 getch() it reads one keystroke
			switch (KeyStroke)
			{
			case PAGE_UP:
				return "PAGE UP";
				break;
			case PAGE_DOWN:
				return "PAGE DOWN";
				break;
			case HOME:
				return "HOME";
				break;
			case END:
				return "END";
				break;
			case UP_ARROW:
				return "UP ARROW";
				break;
			case DOWN_ARROW:
				return "DOWN ARROW";
				break;
			case LEFT_ARROW:
				return "LEFT ARROW";
				break;
			case RIGHT_ARROW:
				return "RIGHT ARROW";
				break;
			case F1:
				return "F1";
				break;
			case F2:
				return "F2";
				break;
			case F3:
				return "F3";
				break;
			case F4:
				return "F4";
				break;
			case F5:
				return "F5";
				break;
			case F6:
				return "F6";
				break;
			case F7:
				return "F7";
				break;
			case F8:
				return "F8";
				break;
			case F9:
				return "F9";
				break;
			case F10:
				return "F10";
				break;
			case F11:
				return "F11";
				break;
			case F12:
				return "F12";
				break;
			default:
				return "UndefinedKey";
			}
		}
		else
			// cout << KeyStroke << " " << x << endl;
			x = KeyStroke;

	return x;
}