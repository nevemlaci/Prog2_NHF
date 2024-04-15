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
class Game final {
	
public:
	/// @brief game instance ctor
	/// @param title title of the game(and the game window)
	Game(const char* title);

	/// @brief runs the game
	void Run();
#ifndef CPORTA

	SDL::Renderer& GetRenderer() { return m_Renderer; }

	SDL::Window& GetWindow() { return m_Window; }
#endif

#ifdef CPORTA
	std::vector<std::unique_ptr<GameObject>>& GetGameObjectVector() {
		return m_GameObjects;
	}
#endif

	const char* GetTitle() const { return m_Title; }

	template<typename T, class... Args>
	T& AddGameObject(Args&&... args) {
		m_GameObjects.push_back(std::make_unique<T>((*this), std::forward<Args>(args)...));
		return dynamic_cast<T&>(*m_GameObjects.back());
	}

	template<typename T = GameObject>
	T& GetGameObject(const std::string& id) {
		for (auto& gameobject : m_GameObjects) {
			GameObject* tryCast = dynamic_cast<T*>(gameobject.get());
			if (gameobject->m_Id == id && tryCast) {
				return dynamic_cast<T&>(*tryCast);
			}
		}
		throw std::runtime_error("GameObject with given id not found.");
	}

	void DeleteGameObject(const std::string& id);
private:
#ifndef CPORTA
	/// @brief Runs the main loop of the game
	void MainLoop();
#endif

	std::vector<std::unique_ptr<GameObject>> m_GameObjects;

	const char* m_Title;

#ifdef CPORTA

#endif
};
}
#endif


