#include "Tiles.h"

void Tiles::CreateMap(RenderContext& ctx,Scene* m_scene){
    std::cout << "Creating World Map" << std::endl;
    std::cout << "World Width: " << ctx.wWidth << std::endl;
    std::cout << "World Height: " << ctx.wHeight << std::endl;

    int width = ctx.wWidth/TILESIZE;
    int height =  ctx.wHeight/TILESIZE;

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
    for(int x = 0; x < height; x++)
    {
        for(int y = 0; y < width; y++)
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
