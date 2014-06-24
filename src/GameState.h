#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Engine.h"

class GameState
{
public:
	virtual void Init(RenderContext& ctx,Scene* m_scene) = 0;
	virtual void Cleanup() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void handleEvents(Engine* rpg, bool &isRunning) = 0;
	virtual void update(Engine* rpg,Scene* m_scene) = 0;
	virtual void render(Engine* rpg,RenderContext& ctx,Scene* m_scene) = 0;

	void ChangeState(Engine* rpg, GameState* state) {
		rpg->ChangeState(state);
	}

protected:
	GameState() { }
};

#endif
