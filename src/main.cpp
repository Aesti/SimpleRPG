#include "Engine.h"

Engine* rpg = 0;

int main (int argc, char *argv[]){

    rpg = new Engine();

    rpg->init("Simple RPG .01", 100, 100, 640, 580, SDL_WINDOW_OPENGL);

    while(rpg->running())
    {
        rpg->handleEvents();
        rpg->update();
        rpg->render();
    }
    rpg->clean();

	return 0;
}