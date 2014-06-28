#ifndef WORLDSTATE_H
#define WORLDSTATE_H

#include "GameState.h"

class WorldState : public GameState
{
public:
	void Init(RenderContext& ctx, Scene* m_scene);
	void Cleanup(RenderContext& ctx,Scene* m_scene);

	void Pause();
	void Resume();

	void handleEvents(Engine* rpg, bool &isRunning);
	void update(Engine* rpg,Scene* m_scene);
	void render(Engine* rpg, RenderContext& ctx,Scene* m_scene);

	static WorldState* Instance() {
		return &m_WorldState;
	}

protected:
	WorldState() { }


private:
	static WorldState m_WorldState;

};

#endif
