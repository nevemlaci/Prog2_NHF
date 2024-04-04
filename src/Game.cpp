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

	void Game::Run() {
		Startup();
		MainLoop();
	}

	

	void Game::Startup() {
		for (auto& object : m_GameObjects) {
			for (auto& component : object->m_Components) {
				component->Startup(*this);
			}
		}
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
