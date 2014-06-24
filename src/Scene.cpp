#include "Scene.h"

#include "RenderContext.h"

#include <iostream>
#include <cassert>

void Scene::addPlayer(GameObject obj, int layer, POINT pt) {

  m_player.reset(new PlayerDesc(obj, pt, layer));

  std::cout << "Adding player" << std::endl;
}

void Scene::add(GameObject obj, int layer, POINT pt, bool isPlayer) {
  if (isPlayer) {
    addPlayer(obj, layer, pt);
    return;
  }

  auto it = m_layers.find(layer);

  GameObjectDesc objDesc(GameObjectDesc(obj, pt));

  if (it != m_layers.end()) {
    it->second.push_back(objDesc);
  } else {
    std::vector<GameObjectDesc> list;
    list.push_back(objDesc);
    m_layers.insert(std::pair<int, std::vector<GameObjectDesc>>(layer, list));
  }
}

void Scene::draw(RenderContext &ctx) {
  if (m_layers.size() == 0) {
    if (m_player != nullptr) {
      m_player->draw(ctx);
    }
    return;
  }

  for (auto it = m_layers.begin(); it != m_layers.end(); ++it) {
    for (auto obj = it->second.begin(); obj != it->second.end(); ++obj) {
      obj->draw(ctx);
    }
    //std::cout << m_player << std::endl;
    if (m_player != nullptr) {
      auto it2(it);
      it2++;
      if (it2 == m_layers.end()) {
        m_player->draw(ctx);
      } else if (it->first <= m_player->layer && m_player->layer < it2->first) {
        m_player->draw(ctx);
      }

    }
  }
}

void Scene::update() {
  movePlayer();
}

#define MOVEMENT_DISTANCE 5
void Scene::movePlayer() {
  if (m_player == nullptr) {
    return;
  }

  assert(m_player != nullptr);

  const Uint8* currentKeyStates = SDL_GetKeyboardState(NULL);
  POINT delta = {0, 0};

  if (currentKeyStates[SDL_SCANCODE_UP]) {
    delta.y -= MOVEMENT_DISTANCE;
  }
  if (currentKeyStates[SDL_SCANCODE_DOWN]) {
    delta.y += MOVEMENT_DISTANCE;
  }
  if (currentKeyStates[SDL_SCANCODE_LEFT]) {
    delta.x -= MOVEMENT_DISTANCE;
  }
  if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
    delta.x += MOVEMENT_DISTANCE;
  }
  m_player->location.x += delta.x;
  m_player->location.y += delta.y;
}