#include "Engine.h"
#include <string>

#include "GameObject.h"
#include "GameState.h"
#include "enums.h"
#include "IntroState.h"

Engine::Engine(std::string title, int xpos, int ypos, int width, int height, int flags) :
m_context(title, xpos, ypos, width, height, flags) {
    init();
}

bool Engine::init()
{
    //Research SDL_CreateWindowAndRenderer
    // m_context = RenderContext(title, xpos, ypos, width, height, flags);
    isRunning = true;
    m_scene = new Scene();
    ChangeState( IntroState::Instance() );

    return true;

}

void Engine::go() {
    while(running())
    {
        handleEvents();
        update();
        render();
    }
    clean();
}

void Engine::ChangeState(GameState* state) 
{
    // cleanup the current state
    if ( !states.empty() ) {
        states.back()->Cleanup(m_context,m_scene);
        states.pop_back();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init(m_context,m_scene);
}

void Engine::PushState(GameState* state)
{
    // pause current state
    if ( !states.empty() ) {
        states.back()->Pause();
    }

    // store and init the new state
    states.push_back(state);
    states.back()->Init(m_context,m_scene);
}

void Engine::PopState()
{
    // cleanup the current state
    if ( !states.empty() ) {
        states.back()->Cleanup(m_context,m_scene);
        states.pop_back();
    }

    // resume previous state
    if ( !states.empty() ) {
        states.back()->Resume();
    }
}
void Engine::handleEvents() 
{
    states.back()->handleEvents(this,isRunning);
}

void Engine::update() 
{
    // let the state update the game
    states.back()->update(this,m_scene);
}

void Engine::render() 
{
    // let the state draw the screen
    states.back()->render(this,m_context,m_scene);
}

void Engine::clean()
{
    while ( !states.empty() ) {
        states.back()->Cleanup(m_context,m_scene);
        states.pop_back();
    }
    // shutdown SDL
    m_context.checkFS(!isFullscreen);
    SDL_Quit();
}
