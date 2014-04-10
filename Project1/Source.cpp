#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <windows.h>
using namespace std;

vector<char> MakeMap(int x, int y);
int ViewMap(vector<char> map, int x, int y);
int Menu();
char TeraType(char lType, char tType);
void SpawnBioCenters(vector<char> *map, int x, int y);
void TreeSpawn(vector<char> *map, int x, int y, int area, int centerX, int centerY, int n, int i);
void TreeRec(vector<char> *map, int startX, int startY, int startDist, int x, int area);
int CountTrees(vector<char> *map, int x, int y);

const int TREE_LIMIT_SMALL = 4;
const int TREE_LIMIT_MED = 18;

// Map Structure
class WorldMap {
public:
	int getXPos();
	int getYPos();
	int getMapVector();
	void makeMap(int newX, int newY);
private:
	int x;
	int y;
	vector<char> map;
};

void WorldMap::makeMap(int newX, int newY){

}




int main()
{
	Menu();
	return 0;
}

int Menu() {
	bool quit = true;
	char menuInput;
	int x, y;
	vector<char> map;
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
			map = MakeMap(x, y);
			system("cls");
			ViewMap(map, x, y);

		}
		else if (menuInput == '2')
			ViewMap(map, x, y);
		else if (menuInput == 'q')
			quit = false;
		else
			cout << "That is not a valid input \n";
	}
	return 0;
}

vector<char> MakeMap(int x, int y) {
	int n, count, i;
	// char tType = 'P', lType = 'P', nType = 'P';
	count = 0;
	vector<char> map;

	for (n = 1; n <= x; n++){
		for (i = 1; i <= y; i++){
			/* if (n > 1)
			tType = map[(n - 1)*i];
			else
			tType = tType;
			lType = nType;
			// nType = TeraType(lType, tType);
			// map.push_back(nType+' ');
			*/
			map.push_back('P');
		}
	}
	// map = SpawnBioCenters(map, x, y);
	SpawnBioCenters(&map, x, y);

	return map;
}

int ViewMap(vector<char> map, int x, int y) {
	int n, i;
	cout << "This is your map\n";
	for (n = 1; n <= x; n++){
		for (i = 1; i <= y; i++){
			// cout << "hello \n";
			if (map[(n - 1)*(i - 1)] == 'T'){
				HANDLE hConsole;
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 2);
				cout << map[(n - 1)*(i - 1)];
				SetConsoleTextAttribute(hConsole, 15);
			}
			else if (map[(n - 1)*(i - 1)] == 'P'){
				HANDLE hConsole;
				hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hConsole, 6);
				cout << map[(n - 1)*(i - 1)];
				SetConsoleTextAttribute(hConsole, 15);
			}
			else
			cout << map[(n - 1)*(i - 1)];
		}
		cout << endl;
	}
	cout << "Trees " << CountTrees(&map, x, y) << endl;
	cout << "press enter to continue";
	cin.ignore();
	cin.get();
	system("cls");
	return 0;
}
/*
char TeraType(char lType, char tType) {
	int seed = rand() % 100 + 1;
	cout << seed << endl;
	if (lType == 'T'){
		if (tType == 'T')
			seed = seed + 50;
		else
			seed = seed + 25;
		if (seed > 60){
			cout << "TREE \n";
			return 'T';
		}
		else if (seed > 20){
			cout << "PLAINS \n";
			return 'P';
		}
		else{
			return 'D';
		}
	}
	if (lType == 'P'){
		if (tType == 'P')
			seed = seed + 50;
		else
			seed = seed + 25;
		if (seed > 60){
			cout << "PLAINS \n";
			return 'P';
		}
		else if (seed > 20){
			cout << "TREE \n";
			return 'T';
		}
		else{
			return 'D';
		}
	}
	if (lType == 'D'){
		if (tType == 'D')
			seed = seed + 50;
		else
			seed = seed + 25;
		if (seed > 80){

			return 'D';
		}
		else if (seed > 60){
			cout << "PLAINS \n";
			return 'P';
		}
		else{
			cout << "TREE \n";
			return 'T';
		}
	}

}

*/

void SpawnBioCenters(vector<char> *map, int x, int y){
	int area = x * y;
	int dArea = area / 5;
	int centerX = x / 2;
	int centerY = y / 2;
	TreeSpawn(map, x, y, area, centerX, centerY, centerY, centerX);
	// return map;
}

void TreeSpawn(vector<char> *map, int x, int y, int area, int centerX, int centerY, int n, int i){
	
	int tArea = area / 4;
	/*
	cout << "position " << n << i << endl;
	int seed = rand() % 100 + 1;
	cout << "seed " << seed << endl;

	double xMod = x;
	double yMod = y;
	double modCenter = (4 / ((xMod + yMod) / 10));
	seed = seed - ((abs(centerX - i) + abs(centerY - n))*modCenter);
	cout << "mod for center " << ((abs(centerX - i) + abs(centerY - n))*modCenter) << endl;
	if (tArea <= 0)
		seed = seed - 18;
	else if (tArea < (area / TREE_LIMIT_MED))
		seed = seed - 16;
	else if (tArea < (area / TREE_LIMIT_SMALL))
		seed = seed - 9;


	tArea = (area / 4) - CountTrees(map, x, y);
	cout << "Tree Remain: " << tArea << endl;

	if (tArea <= (area / 4)){
		if ((i - 1) >= 0)
			TreeSpawn(map, x, y, area, centerX, centerY, n, i - 1);
		if ((i + 2) <= x)
			TreeSpawn(map, x, y, area, centerX, centerY, n, i + 1);
		if ((n - 1) >= 0)
			TreeSpawn(map, x, y, area, centerX, centerY, n - 1, i);
		if ((n + 2) <= x)
			TreeSpawn(map, x, y, area, centerX, centerY, n + 1, i);
	}

	if (seed > 80){
		TreeRec(map, n, i, 0, x, area);
	}

	*/



	// Old version
	int count = 0;

	for (n = 1; n <= x; n++){
		for (i = 1; i <= y; i++){
			cout << "position " << n << i << endl;
			int seed = rand() % 100 + 1;
			cout << "seed " << seed << endl;
			
			double xMod = x;
			double yMod = y;
			double modCenter = (20 / ((xMod + yMod) / 10));
			// seed = seed - ((abs(centerX - i)+abs(centerY - n))*modCenter);
			cout << "mod for center " << ((abs(centerX - i) + abs(centerY - n))*modCenter) << endl;
			if (tArea <= 0)
				seed = seed - 19;
			else if (tArea < (area / TREE_LIMIT_MED))
				seed = seed - 18;
			else if (tArea < (area / TREE_LIMIT_SMALL))
				seed = seed - 12;
				
			if (seed > 80){
				TreeRec(map, n, i, 0, x, area);
			}
			
			tArea = (area / 8) - CountTrees(map, x, y);
			cout << "Tree Remain: " << tArea << endl;
		}
	}
	cout << "Trees " << CountTrees(map, x, y) / area;
	// return map;


}

void TreeRec(vector<char> *map, int indI, int indN, int startDist, int x, int area){
	int seed;
	seed = rand() % 100 + 1;
	if ((seed - (10 * startDist)) > 25){
		// cout << "seed " << seed << endl;
		// cout << "position " << indI*indN << endl;
		// cout << "distance " << startDist << endl;
		cout << "position " << indI << indN << endl;
		(*map)[(indI)*(indN)] = 'T';
		cout << "done" << endl;
		if ((indI - 1) >= 0)
			TreeRec(map, indI - 1, indN, startDist + 1, x, area);
		if ((indI + 2) <= x)
			TreeRec(map, indI + 1, indN, startDist + 1, x, area);
		if ((indN - 1) >= 0)
			TreeRec(map, indI, indN - 1, startDist + 1, x, area);
		if ((indN + 2) <= x)
			TreeRec(map, indI, indN + 1, startDist + 1, x, area);
	}
	// return map;	
}

int CountTrees(vector<char> *map, int x, int y){
	int n, i, count = 0;
	for (n = 1; n <= x; n++){
		for (i = 1; i <= y; i++){
			if ((*map)[(n - 1)*(i - 1)] == 'T'){
				// cout << "tree at " << map[(n - 1)*(i - 1)] << endl;
				count++;
			}
		}
	}
	// cout << count << endl;
	return count;
}