#pragma once 

#include "RenderContext.h"
#include "GameObject.h"
#include <vector>

struct GameObjectDesc {
  GameObject object;
  POINT location;

  GameObjectDesc(GameObject obj, POINT loc)
  : object(obj), location(loc) {} 

  void draw(RenderContext &ctx) {
    object.draw(ctx, location);
  }
};

class Scene {
public:
  Scene() {};
  ~Scene() {};

  void add(GameObject obj, int layer, POINT pt);
  void remove(GameObject obj);

  void draw(RenderContext &ctx);

private:
  std::map<int, std::vector<GameObjectDesc>> m_layers;
};