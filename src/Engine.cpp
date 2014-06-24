#include "Engine.h"
#include <string>

#include "GameObject.h"
#include "enums.h"

Engine::Engine(std::string title, int xpos, int ypos, int width, int height, int flags) :
m_context(title, xpos, ypos, width, height, flags) {
    init();
}

bool Engine::init()
{
    //Research SDL_CreateWindowAndRenderer
    // m_context = RenderContext(title, xpos, ypos, width, height, flags);
    isRunning = true;


    m_scene = new Scene();
    m_scene->add(GameObject(m_context, std::string("res/hero1.png"), std::string("hero")), 0, {300, 400}, true);
    return true;

}

void Engine::go() {
    while(running())
    {
        handleEvents();
        update();
        render();
    }
    clean();
}

void Engine::render()
{
    m_context.clear();
    m_scene->draw(m_context);
    m_context.render();
}

void Engine::clean()
{
    std::cout << "Cleaning up!\n";
}

void Engine::handleEvents()
{
    SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                isRunning = false;
                break;
            default:
            break;
        }
    }
}

void Engine::update(){
    m_scene->update();
}
