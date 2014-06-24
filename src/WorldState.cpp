#include "Engine.h"
#include "GameState.h"
#include "WorldState.h"

WorldState WorldState::m_WorldState;

void WorldState::Init(RenderContext& ctx,Scene* m_scene){
	std::cout << "Initializing WorldState\n";
	//m_scene->add(GameObject(ctx, std::string("res/hero1.png"), std::string("hero")), 0, {300, 400}, true);
}
void WorldState::Cleanup(){}

void WorldState::Pause(){}

void WorldState::Resume(){}

void WorldState::render(Engine* rpg, RenderContext &ctx,Scene* m_scene)
{
    ctx.clear();
    m_scene->draw(ctx);
    ctx.render();
}

void WorldState::handleEvents(Engine* rpg, bool &isRunning){}

void WorldState::update(Engine* rpg,Scene* m_scene){
   	m_scene->update();
}