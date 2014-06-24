#pragma once 

#include <iostream>
#include <SDL2/SDL.h>
#include "SDL_Image.h"
#include <string>
#include <vector>

#include "RenderContext.h"
#include "Scene.h"

class GameState;

class Engine
{
public:
    Engine(std::string title, int xpos, int ypos, int width, int 
          height, int flags);
    ~Engine() {};
    void render();
    void update();
    void handleEvents();
    void go();

    //adding gamestates
    void ChangeState(GameState* state);
    void PushState(GameState* state);
    void PopState();

    void clean();
    bool running() { return isRunning; };

private:
    bool init();

    // the stack of states
    std::vector<GameState*> states;

    RenderContext m_context;
    Scene *m_scene;

    bool isRunning;


};