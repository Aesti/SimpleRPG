
#ifndef INTROSTATE_H
#define INTROSTATE_H

#include "GameState.h"

class IntroState : public GameState
{
public:
	void Init(RenderContext& ctx, Scene* m_scene);
	void Cleanup(RenderContext& ctx,Scene* m_scene);

	void Pause();
	void Resume();

	void handleEvents(Engine* rpg, bool &isRunning);
	void update(Engine* rpg,Scene* m_scene);
	void render(Engine* rpg, RenderContext& ctx,Scene* m_scene);

	static IntroState* Instance() {
		return &m_IntroState;
	}

protected:
	IntroState() { }


private:
	static IntroState m_IntroState;

};

#endif