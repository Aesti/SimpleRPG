#pragma once 

#include "RenderContext.h"
#include "GameObject.h"
#include <vector>

#include "enums.h"
#include <memory>

struct GameObjectDesc {
public:
  GameObject object;
  POINT location;

  GameObjectDesc(GameObject obj, POINT loc)
  : object(obj), location(loc) {}

  void draw(RenderContext &ctx) {
    object.draw(ctx, location);
  }
};

struct PlayerDesc : public GameObjectDesc {
public:
  int layer;

  PlayerDesc(GameObject obj, POINT loc, int layer)
  : GameObjectDesc(obj, loc), layer(layer) {}

};
class Scene {
public:
  Scene() : m_player(nullptr) {};
  ~Scene() {};

  void add(GameObject obj, int layer, POINT pt, bool isPlayer = false);
  void addPlayer(GameObject obj, int layer, POINT pt);
  void remove(GameObject obj);

  void draw(RenderContext &ctx);
  void update();
  
private:
  void movePlayer();
  std::map<int, std::vector<GameObjectDesc>> m_layers;

  std::shared_ptr<PlayerDesc> m_player;
};
