#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <windows.h>
#include "WorldMap.h"
#include "PDcurses/curses.h"
using namespace std;



int Menu();

int main()
{
	initscr();
	// Menu();	
	printw("Hello!");
	refresh();
	while (x != 'q'){
		x = getch();
		mvaddch(1, 0, x);
		move(0, 0);
		refresh();
	}
	
	
	endwin();

	return 0;
}

int Menu() {
	bool quit = true;
	char menuInput;
	int x, y;
	WorldMap NewMap;
	while (quit){
		cout << "This is the main menu \n"
			<< "1. generate a map \n"
			<< "2. view map \n"
			<< "q. quit application \n"
			<< "please choose your option: ";
		cin >> menuInput;
		system("cls");
		if (menuInput == '1'){
			cout << "Enter your desired map dimentions: \nx: ";
			cin >> x;
			cout << "y: ";
			cin >> y;
			NewMap.makeMap(x, y);
			system("cls");
			NewMap.viewMap();

		}
		else if (menuInput == '2')
			NewMap.viewMap();
		else if (menuInput == 'q')
			quit = false;
		else
			cout << "That is not a valid input \n";
	}
	return 0;
}