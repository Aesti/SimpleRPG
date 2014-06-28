#include "Tiles.h"

void Tiles::CreateMap(RenderContext& ctx,Scene* m_scene){
    //screen width divided by tile width is 16
    //screen height divided by tile height is 12
    //192 tiles
    int tileMap[13][17] = {
        {1,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1},
        {1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1},
        {0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1},
        {1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1},
        {1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1},
        {0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1},
        {1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1},
        {0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1},
        {1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1},
        {1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1},
        {0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1},
        {1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1},
        {0,0,0,0,1,1,1,1,1,0,0,0,1,1,1,1}
    };
    std::cout << "Creating World Map" << std::endl;
    for(int x = 0; x < 12; x++)
    {
        for(int y = 0; y < 16; y++)
        {
            if(tileMap[x][y] == 0){
                m_scene->add(GameObject(ctx, std::string("res/grass1.png"), std::string("grass")), 0, {y * TILESIZE, x * TILESIZE}, false);
            }
            else if (tileMap[x][y] == 1){
                m_scene->add(GameObject(ctx, std::string("res/lava1.png"), std::string("lava")), 0, {y * TILESIZE, x * TILESIZE}, false);
            }
            else{
                std::cout << "FAIL :: X equals = " << x << " :: y equals = "<< y << "\n :: value of location = "<< tileMap[x][y] << std::endl << std::endl;
            }
        }
    }

}

void Tiles::update(RenderContext& ctx,Scene* m_scene){

}

void Tiles::draw(RenderContext& ctx,Scene* m_scene){

}
