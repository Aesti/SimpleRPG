#include "Engine.h"
#include <string>

Engine* rpg = 0;

int main (int argc, char *argv[]){
    std::string title = "Simple RPG 0.0.0";
    rpg = new Engine(title, 100, 100, 640, 480, SDL_WINDOW_OPENGL);
    rpg->go();
    
	return 0;
}