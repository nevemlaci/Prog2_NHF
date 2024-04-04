// Game.hpp

#ifndef __Game_H__
#define __Game_H__

#ifndef CPORTA
#include <cpp_SDL_include.hpp>
#endif

#include <vector>
#include <memory>

#include "GameObject.hpp"

namespace SGE2 {
class Game {
public:
	Game(const char*);
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif

	const char* GetTitle() const { return m_Title; }

	SDL::Renderer& GetRenderer() { return m_Renderer; }

	SDL::Window& GetWindow() { return m_Window; }
	
	void Run();

	template<typename T, class... Args>
	GameObject& AddGameObject(Args&&... args) {
		m_GameObjects.push_back(std::make_unique<T>(std::forward<Args>(args)...));
		return (*m_GameObjects.back());
	}
private:
	
	/// @brief differs from the ctor as it gets called when the game is actually beind ran, not when the game object gets instantiated
	void Startup();
	/// @brief Runs the main loop of the game
	void MainLoop();

	std::vector<std::unique_ptr<GameObject>> m_GameObjects;

	const char* m_Title;
#ifndef CPORTA
	SDL::SDL& m_SDL;
	SDL::Window m_Window;
	SDL::Renderer m_Renderer;
#endif

#ifdef CPORTA

#endif
};
}
#endif


