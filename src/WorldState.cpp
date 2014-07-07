#include "Engine.h"
#include "GameState.h"
#include "WorldState.h"

WorldState WorldState::m_WorldState;
Tiles* tile;

void WorldState::Init(RenderContext& ctx,Scene* m_scene){
	std::cout << "Initializing WorldState\n";
    ctx.checkFS((isFullscreen = true)); //reassigning
    Tiles* tile = NULL;
    tile->CreateMap(ctx,m_scene);
    m_scene->add(GameObject(ctx, std::string("res/hero1.png"), std::string("hero")), 0, {300, 200}, true);
}
void WorldState::Cleanup(RenderContext& ctx,Scene* m_scene){}

void WorldState::Pause(){}

void WorldState::Resume(){}

void WorldState::render(Engine* rpg, RenderContext &ctx,Scene* m_scene)
{
    ctx.clear();
    m_scene->draw(ctx);
    ctx.render();
}

void WorldState::handleEvents(Engine* rpg, bool &isRunning){
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
                    std::cout << "Leaving WorldState\n";
                    isRunning = false;
                    //rpg->ChangeState( BattleState::Instance());
                    break;
                }
            default:
            break;
        }
    }
}

void WorldState::update(Engine* rpg,Scene* m_scene){
   	m_scene->update();
}
