#pragma once 

#include <string>
#include "SDL_Image.h"

#include "RenderContext.h"
class GameObject {
  public:
    GameObject(RenderContext &ctx, std::string imgResource, std::string resID);
    GameObject(const GameObject &object) {
      m_imageID = object.getImageID();
    }
    virtual ~GameObject();

    void draw(RenderContext &ctx, int x, int y);
    void draw(RenderContext &ctx, POINT p) { draw(ctx, p.x, p.y); }
    
    std::string const getImageID() const { return m_imageID; }
    void setImageID(std::string id) { m_imageID = id; };
  protected:
    std::string m_imageID;
};