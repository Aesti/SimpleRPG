struct Tileset
{
int firstGridID;
int tileWidth;
int tileHeight;
int spacing;
int margin;
int width;
int height;
int numColumns;
std::string name;
};

class GameTiles
{
public:
	GameTiles();
	~GameTiles() {}

	void update();
	void render();

	std::vector<Tileset>* getTilesets(){return &m_tilesets;}
private:
	std::vector<Tileset> m_tilesets;

};