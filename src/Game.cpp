// Game.cpp

#include "AssetManager.hpp"
#include "Game.hpp"

#ifndef CPORTA

#endif

namespace SGE2 {
#ifndef CPORTA
	Game::Game(const char* title) :
		m_Title(title), m_SDL(SDL::SDL::Get()),
		m_Window(title, 0, 0, 1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP),
		m_Renderer(m_Window, 0, SDL_RENDERER_ACCELERATED),
		m_AssetManager(this),
		m_InputManager(*this)
	{}
#endif

#ifdef CPORTA
	Game::Game(const char* title) : m_Title(title) {}
#endif

	void Game::DeleteGameObject(const std::string& id) {
		for (size_t i = 0; i < m_GameObjects.size(); i++) {
			if (id==m_GameObjects.at(i)->m_Id) {
				m_GameObjects.erase(m_GameObjects.begin() + 1);
				break;
			}
		}
	}

#ifndef CPORTA
	void Game::Run() {
		/*idk what else to do here but I'll surely need something else*/
		std::cout << "Running game: " << m_Title << '\n' << "\tGameObjects count at start: " << m_GameObjects.size() << '\n';
		MainLoop();
	}

	void Game::MainLoop() {
		bool shouldrun = true;
		while (shouldrun) {
			while (m_SDL.PollEvents()) {
				switch (m_SDL.GetEvent().type) {
				case SDL_QUIT:
					shouldrun = false;
					break;
				default:
					break;
				}
				if (!shouldrun) break;
			}
			if (!shouldrun) break;
			m_Renderer.RenderClear();
			for (auto& gameobject_ptr : m_GameObjects) {
				if (gameobject_ptr->Active()) {
					for (auto& component_ptr : gameobject_ptr->m_Components) {
						component_ptr->Update(*this);
					}
				}
			}
			m_Renderer.RenderPresent();
		}
	}
#endif // !CPORTA

#ifndef CPORTA

#endif

#ifdef CPORTA
	
#endif

}
