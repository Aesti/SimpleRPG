#include "Engine.h"
#include "GameState.h"
#include "MenuState.h"

MenuState MenuState::m_MenuState;

void MenuState::Init(RenderContext& ctx,Scene* m_scene){
	std::cout << "Initializing IntroState\n";
	//m_scene->add(GameObject(ctx, std::string("res/hero1.png"), std::string("hero")), 0, {300, 400}, true);
}
void MenuState::Cleanup(){}

void MenuState::Pause(){}

void MenuState::Resume(){}

void MenuState::render(Engine* rpg, RenderContext &ctx,Scene* m_scene)
{
    ctx.clear();
    m_scene->draw(ctx);
    ctx.render();
}

void MenuState::handleEvents(Engine* rpg,bool &isRunning){}

void MenuState::update(Engine* rpg,Scene* m_scene){
   	m_scene->update();
}