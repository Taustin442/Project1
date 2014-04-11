#include "WorldMap.h"
#include <windows.h>
#include <iostream>
// #include "getInput.h"
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
// returns the vector containing the Symbols of the map
/*
vector<Symbol> WorldMap::getMapVector(){
	return map;
}
*/

// makes a map class properlly filled in
// uses spawnBioCenters and its methods
// also clears out the map vector of the class
void WorldMap::makeMap(int newX, int newY){
	x = newX;
	y = newY;
	int n, count, i;
	count = 0;

	map.clear();
	SectorMap temp;
	for (n = 1; n <= y; n++){
		for (i = 1; i <= x; i++){
			// CURRENTLY WORKING HEREEEEEE!!!!!
			temp = SectorMap('P', COLOR_YELLOW, 0);
			map.push_back(temp);
			cout << (map[(n * i) - 1]).getColor() << " " << (map[(n * i) - 1]).getSymbol() << "n: " << n << "i: " << i << endl;
		}
	}
	for (int i = 0; i <= ((x*y) / HEIGHT_MAX_POINTS); i++){
		int locationX = rand() % (x);
		int locationY = rand() % (y);
		int newHeight = (map[locationX*locationY]).getHeight() + 1;
		(map[locationX*locationY]).setHeight(newHeight);
		TrickelDown(locationX, locationY, 0, newHeight - 1);
		clear();
		viewHeightMapNoInput();

	}
	viewHeightMap();
	//SpawnBioCenters();
}

void WorldMap::TrickelDown(int connX, int connY, int distance, int orgHeight){
	
	vector<int> valids;

	/*
	701
	6x2	
	543
	*/
	

	if (
		((connY + 1) < y) 
		&& 
		((map[(connX + 0)*(connY + 1)]).getHeight() < (orgHeight - 1))
		)
	{
		valids.push_back((connX + 0)*(connY + 1));
	}
	if ((((connY + 1) < y) && ((connX + 1) < x)) && ((map[(connX + 1)*(connY + 1)]).getHeight() < (orgHeight - 1))){
		valids.push_back((connX + 1)*(connY + 1));
	}
	if (((connX + 1) < x) && ((map[(connX + 1)*(connY + 0)]).getHeight() < (orgHeight - 1))){
		valids.push_back((connX + 1)*(connY + 0));
	}
	if ((((connY - 1) >= 0) && ((connX + 1) <=x)) && ((map[(connX + 1)*(connY - 1)]).getHeight() < (orgHeight - 1))){
		valids.push_back((connX + 1)*(connY - 1));
	}
	if ((((connY - 1) >= 0) && (map[(connX + 0)*(connY - 1)]).getHeight() < (orgHeight - 1))){
		valids.push_back((connX + 0)*(connY - 1));
	}
	if ((((connY - 1) >= 0) && ((connX - 1) >= 0)) && (map[(connX - 1)*(connY - 1)]).getHeight() < (orgHeight - 1)){
		valids.push_back((connX - 1)*(connY - 1));
	}
	if ((((connX - 1) >= 0) && (map[(connX - 1)*(connY + 0)]).getHeight() < (orgHeight - 1))){
		valids.push_back((connX - 1)*(connY + 0));
	}
	if ((((connY + 1) < y) && ((connX - 1) >= 0)) && (map[(connX - 1)*(connY + 1)]).getHeight() < (orgHeight - 1)){
		valids.push_back((connX - 1)*(connY + 1));
	}


	
	if (valids.size() > 0){
		int scatter = rand() % valids.size();  //0-7
		(map[(valids[scatter])]).setHeight((map[(valids[scatter])]).getHeight() + 1);
		(map[connX*connY]).setHeight(orgHeight);

	}
	

}

// displays the map to the console with either the dynamic or static methods
void WorldMap::viewHeightMap() {
	//checks if the map will fit in the console
	if ((x <= DYM_X) && (y <= DYM_Y)){
		viewHeightMapStatic();
	}
	else if (x > DYM_X && y > DYM_Y){
		viewHeightMapDynamic(DYM_X, DYM_Y);
	}
	else if (x > DYM_X){
		viewHeightMapDynamic(DYM_X, y);
	}
	else{
		viewHeightMapDynamic(x, DYM_Y);
	}
	clear();
}

void WorldMap::viewHeightMapNoInput(){
	int n, i;
	printw("This is your map\n");
	for (n = 1; (n <= DYM_Y) && (n <= y); n++){
		for (i = 1; (i <= DYM_X) && (i <= x); i++){
			color_set((map[(n * i) - 1]).getColor(), NULL);
			char output = (char)((map[(n * i) - 1]).getHeight() + 48);
			addch(output);
			color_set(COLOR_WHITE, NULL);
		}
		printw("\n");

	}
	// cout << "Trees " << CountTrees(&map, x, y) << endl;
	// printw("press enter to continue");
	refresh();
}

void WorldMap::viewHeightMapStatic() {
	int n, i;
	cout << "This is your map\n";
	for (n = 1; n <= x; n++){
		for (i = 1; i <= y; i++){
			color_set((map[(n * i) - 1]).getColor(), NULL);
			char output = (char)((map[(n * i) - 1]).getHeight() + 48);
			addch(output);
			color_set(COLOR_WHITE, NULL);
		}
		printw("\n");

	}
	// cout << "Trees " << CountTrees(&map, x, y) << endl;
	printw("press enter to continue");
	refresh();
	getch();


}

void WorldMap::viewHeightMapDynamic(int finX, int finY) {
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
			color_set((map[(n * i) - 1]).getColor(), NULL);
			char output = (char)((map[(n * i) - 1]).getHeight() + 48);
			addch(output);
			color_set(COLOR_WHITE, NULL);
		}
		printw("\n");
	}
	// cout << "Trees " << CountTrees(&map, x, y) << endl;

	printw("Use arrow keys to navigate. Press any other key to exit");
	refresh();
	int keyInput = getch();
	if (keyInput == KEY_UP){
		if (finY - DYM_Y > 0)
			viewHeightMapDynamic(finX, finY - 1);
		else
			viewHeightMapDynamic(finX, finY);
	}
	else if (keyInput == KEY_DOWN){
		if (finY + 1 <= y)
			viewHeightMapDynamic(finX, finY + 1);
		else
			viewHeightMapDynamic(finX, finY);
	}
	else if (keyInput == KEY_RIGHT){
		if (finX + 1 <= x)
			viewHeightMapDynamic(finX + 1, finY);
		else
			viewHeightMapDynamic(finX, finY);
	}
	else if (keyInput == KEY_LEFT){
		if (finX - DYM_X > 0)
			viewHeightMapDynamic(finX - 1, finY);
		else
			viewHeightMapDynamic(finX, finY);
	}

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
	for (n = 1; (n <= DYM_Y) && (n <= y); n++){
		for (i = 1; (i <= DYM_X) && (i <= x); i++){
			color_set((map[(n * i) - 1]).getColor(), NULL);
			addch((map[(n * i) - 1]).getSymbol());
			color_set(COLOR_WHITE, NULL);
		}
		printw("\n");

	}
	// cout << "Trees " << CountTrees(&map, x, y) << endl;
	// printw("press enter to continue");
	refresh();
}

// displays the map without movement controls
void WorldMap::viewMapStatic() {
	int n, i;
	cout << "This is your map\n";
	for (n = 1; n <= x; n++){
		for (i = 1; i <= y; i++){
			color_set((map[(n * i) - 1]).getColor(), NULL);
			addch((map[(n * i) - 1]).getSymbol());
			color_set(COLOR_WHITE, NULL);
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
			color_set((map[(n * i) - 1]).getColor(), NULL);
			addch((map[(n * i) - 1]).getSymbol());
			color_set(COLOR_WHITE, NULL);
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

	for (int n = 1; n <= y; n++){
		for (int i = 1; i <= x; i++){
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
			else{
				seed = seed - centBias;
			}

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

void WorldMap::TreeSpawn(int currentX, int currentY){

	int area = x * y;
	int tArea = area / 4;
	int count = 0;

	// cout << "position " << n << i << endl;
	int seed = rand() % 100 + 1;
	// cout << "seed " << seed << endl;
	double xMod = x;
	double yMod = y;
	double modCenter = (2 / ((xMod + yMod) / 10));
	double centBias = ((abs((xMod / 2) - currentX) + abs((yMod / 2) - currentY))*modCenter);
	// cout << "mod for center " << centBias << endl;
	if (tArea <= 0)
		seed = seed - centBias - 19;
	else if (tArea < (area / TREE_LIMIT_MED))
		seed = seed - centBias - 18;
	else if (tArea < (area / TREE_LIMIT_SMALL))
		seed = seed - centBias - 12;
	else{
		seed = seed - centBias;
	}

	if (seed > 80){
		TreeRec(currentY, currentX, 0);
	}
	if (seed > 40){
		if ((currentX - 1) >= 0)
			TreeSpawn(currentX - 1, currentY);
		if ((currentX + 2) <= x)
			TreeSpawn(currentX + 1, currentY);
		if ((currentY - 1) >= 0)
			TreeSpawn(currentX, currentY - 1);
		if ((currentY + 2) <= x)
			TreeSpawn(currentX, currentY + 1);
	}
	/*
	ooooooo
	o11111o
	o41113o
	o44x33o
	o42223o
	o22222o
	ooooooo
	*/



	tArea = (area / 4) - CountTrees();
	// cout << "Tree Remain: " << tArea << endl;
	
	
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
		(map[(indI * indN) - 1]).setSymbol('T');
		(map[(indI * indN) - 1]).setColor(COLOR_GREEN);
		clear();
		viewMapNoInput();
		// cout << "done" << endl;
		if ((indI - 1) > 0)
			TreeRec(indI - 1, indN, startDist + 1);
		if ((indI + 2) <= x)
			TreeRec(indI + 1, indN, startDist + 1);
		if ((indN - 1) > 0)
			TreeRec(indI, indN - 1, startDist + 1);
		if ((indN + 2) <= y)
			TreeRec(indI, indN + 1, startDist + 1);

	}
	// return map;	
}
// this counts how many trees are on the map
int WorldMap::CountTrees(){
	int n, i, count = 0;
	for (n = 1; n <= x; n++){
		for (i = 1; i <= y; i++){
			if (((map)[(n - 1)*(i - 1)]).getSymbol() == 'T'){
				// cout << "tree at " << map[(n - 1)*(i - 1)] << endl;
				count++;
			}
		}
	}
	// cout << count << endl;
	return count;
}
