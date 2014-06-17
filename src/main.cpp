#include <iostream>
#include <SDL2/SDL.h>

#ifdef TARGET_OS_MAC
  //#include <SDL2_image/SDL_image.h>
#endif

#ifdef __linux__
  // Linux Includes Here
  #include <SDL2/SDL_image.h>
#endif

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//square tiles
const int TILE_SIZE = 40;
/**
* Log an SDL error with some error message to the output stream of our choice
* @param os The output stream to write the message to
* @param msg The error message to write, format will be msg error: SDL_GetError()
*/
void logSDLError(std::ostream &os, const std::string &msg){
    os << msg << " error: " << SDL_GetError() << std::endl;
}
/**
* Loads an image into a texture on the rendering device
* @param file The image file to load
* @param ren The renderer to load the texture onto
* @return the loaded texture, or nullptr if something went wrong.
*/
SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren){
    SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
    if (texture == nullptr)     
        logSDLError(std::cout, "LoadTexture");
    return texture;
}
/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, with some desired
* width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
* @param w The width of the texture to draw
* @param h The height of the texture to draw
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y, int w, int h){
    //Setup the destination rectangle to be at the position we want
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    SDL_RenderCopy(ren, tex, NULL, &dst);
}
/**
* Draw an SDL_Texture to an SDL_Renderer at position x, y, preserving
* the texture's width and height
* @param tex The source texture we want to draw
* @param ren The renderer we want to draw to
* @param x The x coordinate to draw to
* @param y The y coordinate to draw to
*/
void renderTexture(SDL_Texture *tex, SDL_Renderer *ren, int x, int y){
    int w, h;
    SDL_QueryTexture(tex, NULL, NULL, &w, &h);
    renderTexture(tex, ren, x, y, w, h);
}
int main (int argc, char *argv[]){
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    //init image system to avoid delay when loading first image
    if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
    logSDLError(std::cout, "IMG_Init");
    return 1;
    }

    //Research SDL_CreateWindowAndRenderer
    SDL_Window *window = NULL;
    window = SDL_CreateWindow("RPG Game", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_OPENGL);

    SDL_Renderer *renderer = NULL;
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture *background = loadTexture("res/grass1.png", renderer);
    //Make sure they both loaded ok
    if (background == nullptr)
        return 4;


    SDL_Event e;
    //normal game loop
    bool quit = false;    
    while(!quit){
        while (SDL_PollEvent(&e)){
        if (e.type == SDL_QUIT)
            quit = true;
        if (e.type == SDL_KEYDOWN)
            quit = true;
        if (e.type == SDL_MOUSEBUTTONDOWN)
            quit = true;
    }
        SDL_RenderClear(renderer);

        renderTexture(background,renderer,0,0,40,40);
        SDL_RenderPresent(renderer);

    }

    //cleaning up
    SDL_DestroyTexture(background);
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
	return 0;
}