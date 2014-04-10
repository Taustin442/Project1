#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <vector>
#include "SectorMap.h"
using namespace std;

const int TREE_LIMIT_SMALL = 4;
const int TREE_LIMIT_MED = 18;
const int DYM_X = 70;
const int DYM_Y = 30;

// WorldMap Class
class WorldMap {
public:
	int getXPos();
	int getYPos();
	vector<char> getMapVector();
	void makeMap(int newX, int newY);
	void viewMap();

private:
	void viewMapNoInput();
	void viewMapStatic();
	void viewMapDynamic(int finX, int finY);
	void SpawnBioCenters();
	void TreeSpawn();
	int CountTrees();
	void TreeRec(int indI, int indN, int startDist);
	int x;
	int y;
	vector<char> map;
	// vector<SectorMap> map;
};


#endif //WORLDMAP_H