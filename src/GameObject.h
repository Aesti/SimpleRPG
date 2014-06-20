#ifndef __GameObject__
#define __GameObject__

#include "SDL_Image.h"

class GameObject {
  public:
    GameObject();
    virtual ~GameObject();

    void draw();

};
#endif