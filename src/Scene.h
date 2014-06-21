#pragma once 

#include "GameObject.h"
#include <vector>

class Scene {
public:
  Scene() {};
  ~Scene() {};

  void add(GameObject obj, int layer);
  void remove(GameObject obj);

  void draw(RenderContext &ctx);

private:
  std::map<int, std::vector<GameObject>> m_layers;
};