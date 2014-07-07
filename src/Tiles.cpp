#include "Tiles.h"

void toIso(int *j, int *i){
    int x = 0;
    int y = 0;;
    x = *j-*i;
    y = (*j + *i) / 2;
    *j = y;
    *i = x;
}
void Tiles::CreateMap(RenderContext& ctx,Scene* m_scene){
    std::cout << "Creating World Map" << std::endl;

    int width = 640/TILESIZE;
    int height =  480/TILESIZE;

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

    int j = 0;
    int i = 0;

    for(int x = 0; x < height; x++)
    {
        for(int y = 0; y < width; y++)
        {
            j = y * TILESIZE;
            i = x * TILESIZE;
            //toIso(&j,&i);
            std::cout << j << " " << i << std::endl;

            if(tileMap[x][y] == 0){
                m_scene->add(GameObject(ctx, std::string("res/grass1.png"), std::string("grass")), 0, {j,i}, false);
            }
            else if (tileMap[x][y] == 1){
                m_scene->add(GameObject(ctx, std::string("res/lava1.png"), std::string("lava")), 0, {j,i}, false);
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
