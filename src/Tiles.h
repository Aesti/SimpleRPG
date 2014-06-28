#ifndef TILES_H
#define TILES_H

#include "Engine.h"

const int TILESIZE = 40;

class Tiles{
public:
    Tiles();
    ~Tiles(){}
    void CreateMap(RenderContext& ctx,Scene* m_scene);
    void update(RenderContext& ctx,Scene* m_scene);
    void draw(RenderContext& ctx,Scene* m_scene);
private:
};


#endif // TILES_H
