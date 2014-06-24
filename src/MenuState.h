#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "GameState.h"

class MenuState : public GameState
{
public:
	void Init(RenderContext& ctx, Scene* m_scene);
	void Cleanup(RenderContext& ctx,Scene* m_scene);

	void Pause();
	void Resume();

	void handleEvents(Engine* rpg, bool &isRunning);
	void update(Engine* rpg,Scene* m_scene);
	void render(Engine* rpg, RenderContext& ctx,Scene* m_scene);

	static MenuState* Instance() {
		return &m_MenuState;
	}

protected:
	MenuState() { }


private:
	static MenuState m_MenuState;

};

#endif