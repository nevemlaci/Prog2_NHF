// Game.cpp

#include "Game.hpp"

#ifndef CPORTA

#endif

namespace SGE2 {
	Game::Game(const char* title) : 
		m_Title(title), m_SDL(SDL::SDL::Get()), 
		m_Window(title, 0, 0, 1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP), 
		m_Renderer(m_Window, 0, SDL_RENDERER_ACCELERATED) 
	{}

	void Game::DeleteGameObject(const std::string& id) {
		for (size_t i = 0; i < m_GameObjects.size(); i++) {
			if (id==m_GameObjects.at(i)->m_Id) {
				m_GameObjects.erase(m_GameObjects.begin() + 1);
				break;
			}
		}
	}

	void Game::Run() {
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

			for (auto& object : m_GameObjects) {
				for (auto& component : object->m_Components) {
					component->Update(*this);
				}
			}
		}
	}

#ifndef CPORTA

#endif

#ifdef CPORTA
	
#endif

}
