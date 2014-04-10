#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <windows.h>
#include "Clock.h"
#include "WorldMap.h"
#include <curses.h>
#include "PDcurses/curses.h"
#include <cmath>
using namespace std;


int getIntInput(int maxDigit);
int Menu();

int main()
{
	char input;
	cout << "d for debug" << endl;
	cin >> input;
	if (input == 'd'){
		int secs;
		char quit = 'n';
		Clock TestClock;
		while (quit == 'n'){
			cout << "Seconds: ";
			cin >> secs;
			TestClock.IncrementTimeSec(secs);
			TestClock.OutputTime();
			cout << "quit?" << endl;
			cin >> quit;
		}
		

	}
	else{
		WINDOW *wndPnt = initscr();
		start_color();
		// init_pair(0, COLOR_BLACK, COLOR_BLACK);
		init_pair(1, COLOR_BLUE, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_CYAN, COLOR_BLACK);
		init_pair(4, COLOR_RED, COLOR_BLACK);
		init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
		init_pair(6, COLOR_YELLOW, COLOR_BLACK);
		init_pair(7, COLOR_WHITE, COLOR_BLACK);
		keypad(wndPnt, TRUE);
		resize_term(35, 160);
		Menu();

		/*
		int x = 0;
		while (x != 'q'){
		refresh();
		x = getch();
		mvprintw(1, 0, "%i", x);
		refresh();
		getch();
		move(0, 0);
		clear();
		}

		*/

		endwin();
	}

	return 0;
}

int Menu() {
	bool quit = true;
	int menuInput;
	int x, y;
	WorldMap NewMap;
	while (quit){
		printw(
			"This is the main menu \n"
			"1. generate a map \n"
			"2. view map \n"
			"q. quit application \n"
			"please choose your option: "
			);
		refresh();
		nocbreak();
		menuInput = getch();
		cbreak();
		clear();
		if (menuInput == '1'){
			x = 0;
			y = 0;
			printw("Enter your desired map dimentions: \nx: ");
			x = getIntInput(4);
			printw("\n");
			printw("y: ");
			y = getIntInput(4);
			NewMap.makeMap(x, y);
			clear();
			NewMap.viewMap();

		}
		else if (menuInput == '2')
			NewMap.viewMap();
		else if (menuInput == 'q')
			quit = false;
		else
			printw("That is not a valid input \n");
	}
	return 0;
}

int getIntInput(int maxDigit){
	int buf = 0;
	int sum = 0;
	int array[4] = {};
	int lengthOfInt = 0;
	int digit = 0;
	while (buf != 10){
		buf = getch();
		if ((buf >= 48) && (buf <= 57)){
			array[lengthOfInt] = buf - 48;
			lengthOfInt++;
		}
	}
	lengthOfInt--;
	while (lengthOfInt >= 0){
			sum = sum + (pow(10, digit) * (array[lengthOfInt]));
			lengthOfInt--;
			digit++;
	}
	return sum;
}