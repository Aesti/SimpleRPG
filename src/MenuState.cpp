#include "Engine.h"
#include "GameState.h"
#include "MenuState.h"
#include "WorldState.h"

MenuState MenuState::m_MenuState;

void MenuState::Init(RenderContext& ctx,Scene* m_scene){
	std::cout << "Initializing MenuState\n";
}
void MenuState::Cleanup(RenderContext& ctx,Scene* m_scene){
    m_scene->remove();
}

void MenuState::Pause(){}

void MenuState::Resume(){}

void MenuState::render(Engine* rpg, RenderContext &ctx,Scene* m_scene)
{
    ctx.clear();
    m_scene->draw(ctx);
    ctx.draw_text("Hello World!",28,0,150);
    ctx.render();
}

void MenuState::handleEvents(Engine* rpg,bool &isRunning){
SDL_Event event;
    if(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
            	switch (event.key.keysym.sym){
            		case SDLK_RETURN:
            		std::cout << "Leaving MenuState\n";
                    rpg->ChangeState( WorldState::Instance());
            		break;
            	}
            default:
            break;
        }
    }


}

void MenuState::update(Engine* rpg,Scene* m_scene){
   	m_scene->update();
}
