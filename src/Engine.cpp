#include "Engine.h"
#include <string>

bool Engine::init(std::string title, int xpos, int ypos, int width, 
int height, int flags)
{
    //Research SDL_CreateWindowAndRenderer
    m_context = new RenderContext(title, xpos, ypos, width, height, flags);
    isRunning = true;

    m_context->load_image("res/grass1.png", "grass");

    return true;

}
void Engine::render()
{
    m_context->clear();
    m_context->draw_image("grass",0,0,40,40);
    m_context->draw_image("grass",500,400,100,100);
    m_context->render();
}

void Engine::clean()
{
    std::cout << "Cleaning up!\n";
    delete m_context;
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
    
}
