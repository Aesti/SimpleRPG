#ifndef TILEMANAGER_H
#define TILEMANAGER_H
#include <map>

//tile sprites
const int TILE_GRASS = 0;

class GameTiles
{
public:
	ImageManager();
	~ImageManager() {}

	void update();
	void render();

protected:
	//std::map<std::string,

};