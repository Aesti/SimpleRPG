#include "Engine.h"
#include "GameState.h"
#include "IntroState.h"

IntroState IntroState::m_IntroState;

void IntroState::Init(RenderContext& ctx,Scene* m_scene){
	std::cout << "Initializing IntroState\n";
	m_scene->add(GameObject(ctx, std::string("res/Splash.png"), std::string("introsplash")), 0, {0, 0}, false);
}
void IntroState::Cleanup(){}

void IntroState::Pause(){}

void IntroState::Resume(){}

void IntroState::render(Engine* rpg, RenderContext &ctx,Scene* m_scene)
{
    ctx.clear();
    m_scene->draw(ctx);
    ctx.render();
}

void IntroState::handleEvents(Engine* rpg, bool &isRunning){
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

void IntroState::update(Engine* rpg,Scene* m_scene){
   	m_scene->update();
}