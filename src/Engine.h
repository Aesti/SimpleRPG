#ifndef __Engine__
#define __Engine__

#include <iostream>
#include <SDL2/SDL.h>
#include "SDL_Image.h"
#include "RenderContext.h"
#include <string>

class Engine
{
public:
    Engine() {}
    ~Engine() {}
    bool init(std::string title, int xpos, int ypos, int width, int 
          height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running() { return isRunning; }
private:
  SDL_Window *m_window = NULL;
  RenderContext *m_context;
  bool isRunning;
};
#endif