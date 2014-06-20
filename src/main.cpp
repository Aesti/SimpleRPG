#include "Engine.h"
#include <string>

Engine* rpg = 0;

int main (int argc, char *argv[]){

    rpg = new Engine();

    std::string title = "Simple RPG 0.0.0";
    rpg->init(title, 100, 100, 640, 580, SDL_WINDOW_OPENGL);

    while(rpg->running())
    {
        rpg->handleEvents();
        rpg->update();
        rpg->render();
    }
    rpg->clean();

	return 0;
}