#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main (int argc, char **argv){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    //Research SDL_CreateWindowAndRenderer
    SDL_Window *window = NULL;
    window = SDL_CreateWindow("RPG Game", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,200,200,SDL_WINDOW_OPENGL);

    SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //load textures
    SDL_Texture* grass1_image = NULL;
    grass1_image = IMG_LoadTexture(renderer,"res/grass1.png");

    SDL_Rect grass_rect;
    grass_rect.x = 10;
    grass_rect.y = 10;
    grass_rect.w = 100;
    grass_rect.h = 100;


    SDL_Event* mainEvent = new SDL_Event();
    //normal game loop
    bool quit = false;    
    while(!quit && mainEvent->type != SDL_QUIT){
        SDL_PollEvent(mainEvent);
        SDL_RenderClear(renderer);

        SDL_RenderCopy(renderer,grass1_image,NULL,&grass_rect);

        SDL_RenderPresent(renderer);

    }

    //cleaning up
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete mainEvent;

    SDL_Quit();
	return 0;
}