#pragma once 

#include "RenderContext.h"
#include "GameObject.h"
#include <vector>
#include "Camera.h"

#include "enums.h"
#include <memory>

struct GameObjectDesc {
public:
  GameObject object;
  POINT location;
  Camera *camera;

  GameObjectDesc(GameObject obj, POINT loc, Camera *cam)
  : object(obj), location(loc), camera(cam) {}

  void draw(RenderContext &ctx) {
    object.draw(ctx, camera->translateToView(location));
  }
};

struct PlayerDesc : public GameObjectDesc {
public:
  int layer;

  PlayerDesc(GameObject obj, POINT loc, Camera* cam, int layer)
  : GameObjectDesc(obj, loc, cam), layer(layer) {}

};
class Scene {
public:
  Scene() : m_player(nullptr), m_camera() {};
  ~Scene() {};

  void add(GameObject obj, int layer, POINT pt, bool isPlayer = false);
  void addPlayer(GameObject obj, int layer, POINT pt);
  void remove();

  void draw(RenderContext &ctx);
  void update();
  
private:
  void movePlayer();
  std::map<int, std::vector<GameObjectDesc>> m_layers;

  std::shared_ptr<PlayerDesc> m_player;

  Camera m_camera;
};
