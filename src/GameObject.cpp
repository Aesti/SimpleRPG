#include "GameObject.h"

#include <iostream>

GameObject::GameObject(RenderContext &ctx, std::string imgRes, std::string resID)
: m_imageID(resID) {
  ctx.load_image(imgRes, m_imageID);
}

GameObject::~GameObject() {

}

void GameObject::draw(RenderContext &ctx, int x, int y) {
  ctx.draw_image(m_imageID, x, y);
}