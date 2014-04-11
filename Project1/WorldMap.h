#ifndef WORLDMAP_H
#define WORLDMAP_H

#include <vector>
#include "SectorMap.h"
using namespace std;

const int TREE_LIMIT_SMALL = 4;
const int TREE_LIMIT_MED = 18;
const int DYM_X = 70;
const int DYM_Y = 30;
const int HEIGHT_MAX_POINTS = 3;
const int HEIGHT_CHECK_DISTANCE = 3;

// WorldMap Class
class WorldMap {
public:
	int getXPos();
	int getYPos();
	// vector<vector<SectorMap>> getMapVector();
	vector<SectorMap> getMapVector();
	void makeMap(int newX, int newY);
	void viewMap();
	void TrickelDown(int x, int y, int distance, int orgHeight);

private:
	void viewHeightMap();
	void viewHeightMapNoInput();
	void viewHeightMapStatic();
	void viewHeightMapDynamic(int finX, int finY);
	void viewMapNoInput();
	void viewMapStatic();
	void viewMapDynamic(int finX, int finY);
	void SpawnBioCenters();
	void TreeSpawn();
	void TreeSpawn(int currentX, int currentY);
	int CountTrees();
	void TreeRec(int indI, int indN, int startDist);
	int x;
	int y;
	// vector<vector<SectorMap>> map;
	vector<SectorMap> map;
};


#endif //WORLDMAP_H