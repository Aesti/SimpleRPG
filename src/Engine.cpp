#include "Engine.h"

bool Engine::init(const char* title, int xpos, int ypos, int width, 
int height, int flags)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    //Research SDL_CreateWindowAndRenderer

    window = SDL_CreateWindow(title, xpos,
        ypos, width, height, flags);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    std::cout << "SDL INIT SUCCESS!\n";
    isRunning = true;

    return true;

}
void Engine::render()
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);

}
void Engine::clean()
{
    std::cout << "Cleaning up!\n";
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
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