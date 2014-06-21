#include "Scene.h"

#include "RenderContext.h"

#include <iostream>

void Scene::add(GameObject obj, int layer) {
  auto it = m_layers.find(layer);
  if (it != m_layers.end()) {
    it->second.push_back(obj);
  } else {
    std::vector<GameObject> list;
    list.push_back(obj);
    m_layers.insert(std::pair<int, std::vector<GameObject>>(layer, list));
  }
}

void Scene::draw(RenderContext &ctx) {
  for (auto it = m_layers.begin(); it != m_layers.end(); ++it) {
    for (auto obj = it->second.begin(); obj != it->second.end(); ++obj) {
      std::cout << "Drawing " << obj->getImageID() << " at 300, 200" << std::endl;
      obj->draw(ctx, 300, 200);
    }
  }

}