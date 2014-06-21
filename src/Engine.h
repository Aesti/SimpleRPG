#pragma once 

#include <iostream>
#include <SDL2/SDL.h>
#include "SDL_Image.h"
#include <string>

#include "RenderContext.h"
#include "Scene.h"

class Engine
{
public:
    Engine(std::string title, int xpos, int ypos, int width, int 
          height, int flags);
    ~Engine() {};
    void render();
    void update();
    void handleEvents();
    void clean();
    bool running() { return isRunning; };
private:
    bool init();

    RenderContext m_context;
    Scene *m_scene;

    bool isRunning;


};