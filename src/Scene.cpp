#include "Scene.h"

#include "RenderContext.h"

#include <iostream>

void Scene::add(GameObject obj, int layer, POINT pt) {
  auto it = m_layers.find(layer);
  if (it != m_layers.end()) {
    it->second.push_back(GameObjectDesc(obj, pt));
  } else {
    std::vector<GameObjectDesc> list;
    list.push_back(GameObjectDesc(obj, pt));
    m_layers.insert(std::pair<int, std::vector<GameObjectDesc>>(layer, list));
  }
}

void Scene::draw(RenderContext &ctx) {
  for (auto it = m_layers.begin(); it != m_layers.end(); ++it) {
    for (auto obj = it->second.begin(); obj != it->second.end(); ++obj) {
      obj->draw(ctx);
    }
  }

}
