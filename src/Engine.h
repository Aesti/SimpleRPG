#ifndef __Engine__
#define __Engine__

#include <iostream>
#include <SDL2/SDL.h>

#ifdef TARGET_OS_MAC
  #include <SDL2_image/SDL_image.h>
#endif

#ifdef __linux__
  // Linux Includes Here
  #include <SDL2/SDL_image.h>
#endif

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Engine
{
public:
    Engine() {}
    ~Engine() {}
    bool init(const char* title, int xpos, int ypos, int width, int 
          height, int flags);
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running() { return isRunning; }
private:
  SDL_Window *window = NULL;
  SDL_Renderer *renderer = NULL;
  bool isRunning;
};
#endif