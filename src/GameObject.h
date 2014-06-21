#pragma once 

#include <string>
#include "SDL_Image.h"

#include "RenderContext.h"
class GameObject {
  public:
    GameObject(RenderContext &ctx, std::string imgResource, std::string resID);
    virtual ~GameObject();

    void draw(RenderContext &ctx, int x, int y);

    std::string getImageID() { return m_imageID; }
    void setImageID(std::string id) { m_imageID = id; };
  protected:
    std::string m_imageID;
};