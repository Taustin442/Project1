#include "WorldMap.h"
#include <windows.h>
#include <iostream>
#include "getInput.h"
#include "PDcurses/curses.h"

using namespace std;

// returns the hotizontal length of the map
int WorldMap::getXPos(){
	return x;
}
// returns the verticle length of the map
int WorldMap::getYPos(){
	return y;
}
// returns the vector containing the visuals of the map
vector<char> WorldMap::getMapVector(){
	return map;
}

// makes a map class properlly filled in
// uses spawnBioCenters and its methods
// also clears out the map vector of the class
void WorldMap::makeMap(int newX, int newY){
	x = newX;
	y = newY;
	int n, count, i;
	count = 0;

	map.clear();

	for (n = 1; n <= x; n++){
		for (i = 1; i <= y; i++){
			map.push_back('P');
		}
	}
	SpawnBioCenters();
}

// displays the map to the console with either the dynamic or static methods
void WorldMap::viewMap() {
	//checks if the map will fit in the console
	if ((x <= DYM_X) && (y <= DYM_Y)){
		viewMapStatic();
	}
	else if (x > DYM_X && y > DYM_Y){
		viewMapDynamic(DYM_X, DYM_Y);
	}
	else if (x > DYM_X){
		viewMapDynamic(DYM_X, y);
	}
	else{
		viewMapDynamic(x, DYM_Y);
	}
	clear();
}

void WorldMap::viewMapNoInput(){
	int n, i;
	printw("This is your map\n");
	for (n = 1; n <= DYM_Y; n++){
		for (i = 1; i <= DYM_X; i++){
			if (map[(n - 1)*(i - 1)] == 'T'){
				color_set(COLOR_GREEN, NULL);
				addch(map[(n - 1)*(i - 1)]);
				color_set(COLOR_WHITE, NULL);
			}
			else if (map[(n - 1)*(i - 1)] == 'P'){
				color_set(COLOR_YELLOW, NULL);
				addch(map[(n - 1)*(i - 1)]);
				color_set(COLOR_WHITE, NULL);
			}
			else
				addch(map[(n - 1)*(i - 1)]);
		}
		printw("\n");

	}
	// cout << "Trees " << CountTrees(&map, x, y) << endl;
	printw("press enter to continue");
	refresh();
}

// displays the map without movement controls
void WorldMap::viewMapStatic() {
	int n, i;
	cout << "This is your map\n";
	for (n = 1; n <= x; n++){
		for (i = 1; i <= y; i++){
			if (map[(n - 1)*(i - 1)] == 'T'){
				color_set(COLOR_GREEN, NULL);
				addch(map[(n - 1)*(i - 1)]);
				color_set(COLOR_WHITE, NULL);
			}
			else if (map[(n - 1)*(i - 1)] == 'P'){
				color_set(COLOR_YELLOW, NULL);
				addch(map[(n - 1)*(i - 1)]);
				color_set(COLOR_WHITE, NULL);
			}
			else
				addch(map[(n - 1)*(i - 1)]);
		}
		printw("\n");

	}
	// cout << "Trees " << CountTrees(&map, x, y) << endl;
	printw("press enter to continue");
	refresh();
	getch();


}
// displays as much map as possible and lets the user schroll
void WorldMap::viewMapDynamic(int finX, int finY) {
	clear();
	printw("This is your map\n");
	int orgY = 1, orgX = 1;
	if (finY > DYM_Y){
		orgY = finY - (DYM_Y - 1);
	}
	if (finX > DYM_X){
		orgX = finX - (DYM_X - 1);
	}

	for (int n = orgY; n <= finY; n++){
		for (int i = orgX; i <= finX; i++){
			if (map[(n - 1)*(i - 1)] == 'T'){
				attron(COLOR_PAIR(2));
				// color_set(COLOR_GREEN, NULL);
				addch(map[(n - 1)*(i - 1)]);
				// color_set(COLOR_WHITE, NULL);
				attron(COLOR_PAIR(7));
			}
			else if (map[(n - 1)*(i - 1)] == 'P'){
				attron(COLOR_PAIR(6));
				// color_set(COLOR_YELLOW, NULL);
				addch(map[(n - 1)*(i - 1)]);
				// color_set(COLOR_WHITE, NULL);
				attron(COLOR_PAIR(7));
			}
			else
				addch(map[(n - 1)*(i - 1)]);
		}
		printw("\n");
	}
	// cout << "Trees " << CountTrees(&map, x, y) << endl;

	printw("Use arrow keys to navigate. Press any other key to exit");
	refresh();
	int keyInput = getch();
	if (keyInput == KEY_UP){
		if (finY - DYM_Y > 0)
			viewMapDynamic(finX, finY - 1);
		else
			viewMapDynamic(finX, finY);
	}
	else if (keyInput == KEY_DOWN){
		if (finY + 1 <= y)
			viewMapDynamic(finX, finY + 1);
		else
			viewMapDynamic(finX, finY);
	}
	else if (keyInput == KEY_RIGHT){
		if (finX + 1 <= x)
			viewMapDynamic(finX + 1, finY);
		else
			viewMapDynamic(finX, finY);
	}
	else if (keyInput == KEY_LEFT){
		if (finX - DYM_X > 0)
			viewMapDynamic(finX - 1, finY);
		else
			viewMapDynamic(finX, finY);
	}

}

// intitiates verious biom spawns
void WorldMap::SpawnBioCenters(){
	int area = x * y;
	int dArea = area / 5;
	TreeSpawn();

}
// makes tree locations
void WorldMap::TreeSpawn(){

	int area = x * y;
	int tArea = area / 4;
	int count = 0;

	for (int n = 0; n <= y; n++){
		for (int i = 0; i <= x; i++){
			// cout << "position " << n << i << endl;
			int seed = rand() % 100 + 1;
			// cout << "seed " << seed << endl;

			double xMod = x;
			double yMod = y;
			double modCenter = (2 / ((xMod + yMod) / 10));
			double centBias = ((abs((xMod / 2) - i) + abs((yMod / 2) - n))*modCenter);
			// cout << "mod for center " << centBias << endl;
			if (tArea <= 0)
				seed = seed - centBias - 19;
			else if (tArea < (area / TREE_LIMIT_MED))
				seed = seed - centBias - 18;
			else if (tArea < (area / TREE_LIMIT_SMALL))
				seed = seed - centBias - 12;

			if (seed > 80){
				TreeRec(n, i, 0);
			}

			tArea = (area / 4) - CountTrees();
			// cout << "Tree Remain: " << tArea << endl;
		}
	}
	cout << "Trees " << CountTrees() << endl;
	cout << "Intended " << tArea << endl;


}
// once a spawn center is found this spreads trees around it recursively
void WorldMap::TreeRec(int indI, int indN, int startDist){
	int area = x * y;
	int seed;
	seed = rand() % 100 + 1;
	if ((seed - (10 * startDist)) > 50){
		/*
		if (indI == 0){
		cout << indI << endl;
		cout << "seed " << seed << endl;
		cout << "position " << indI*indN << endl;
		cout << "distance " << startDist << endl;
		}
		if (indN == 0){
		cout << indI << endl;
		cout << "seed " << seed << endl;
		cout << "position " << indI*indN << endl;
		cout << "distance " << startDist << endl;
		}
		*/
		// cout << "seed " << seed << endl;
		// cout << "position " << indI*indN << endl;
		// cout << "distance " << startDist << endl;
		// cout << "position " << indI << indN << endl;
		map[(indI)*(indN)] = 'T';
		clear();
		viewMapNoInput();
		// cout << "done" << endl;
		if ((indI - 1) >= 0)
			TreeRec(indI - 1, indN, startDist + 1);
		if ((indI + 2) <= x)
			TreeRec(indI + 1, indN, startDist + 1);
		if ((indN - 1) >= 0)
			TreeRec(indI, indN - 1, startDist + 1);
		if ((indN + 2) <= x)
			TreeRec(indI, indN + 1, startDist + 1);

	}
	// return map;	
}
// this counts how many trees are on the map
int WorldMap::CountTrees(){
	int n, i, count = 0;
	for (n = 1; n <= x; n++){
		for (i = 1; i <= y; i++){
			if ((map)[(n - 1)*(i - 1)] == 'T'){
				// cout << "tree at " << map[(n - 1)*(i - 1)] << endl;
				count++;
			}
		}
	}
	// cout << count << endl;
	return count;
}
