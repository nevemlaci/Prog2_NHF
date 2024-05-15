// Game.cpp

#include "AssetManager.hpp"
#include "Game.hpp"
#include "Time.hpp"

#ifndef CPORTA

#endif

namespace SGL2 {
#ifndef CPORTA
	Game_t::Game_t() :
		m_Title(""), m_SDL(SDL::SDL::Get()),
		m_Window("", 0, 0, 1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP),
		m_Renderer(m_Window, 0, SDL_RENDERER_ACCELERATED),
		m_MainCamera(Vector2(0,0), Vector2(0,0))
	{
		SDL_DisplayMode dm;
		SDL_GetDesktopDisplayMode(0, &dm);
		m_ScreenSize.x = static_cast<float>(dm.w);
		m_ScreenSize.y = static_cast<float>(dm.h);
		m_MainCamera = Camera(Vector2(0, 0), m_ScreenSize);
	}
#endif

#ifdef CPORTA
	Game_t::Game_t() : m_Title("") {}
#endif

	void Game_t::DeleteGameObject(const std::string& id) {
		for (size_t i = 0; i < m_GameObjects.size(); i++) {
			if (id==m_GameObjects.at(i)->m_Id) {
				m_GameObjects.erase(m_GameObjects.begin() + 1);
				break;
			}
		}
	}

#ifndef CPORTA
	void Game_t::Run() {
		/*idk what else to do here but I'll surely need something else*/
		std::cout << "Running game: " << m_Title << '\n' << "\tGameObjects count at start: " << m_GameObjects.size() << '\n';
		m_HasStarted = true;
		for (auto& gameobject_ptr : m_GameObjects) {
			for (auto& component_ptr : gameobject_ptr->m_Components) {
				component_ptr->Startup();
			}
		}
		MainLoop();
	}

	void Game_t::MainLoop() {
		bool shouldrun = true;
		while (shouldrun) {
		Time().FrameStart(); 
		//std::cout << (1.0 / (Time().DeltaTime() / Time().ratio)) << " FPS\n";
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
						component_ptr->Update();
					}
				}
			}
			m_Renderer.RenderPresent();
		}
		SDL_Quit();
	}
#endif // !CPORTA

#ifndef CPORTA

#endif

#ifdef CPORTA
	
#endif

	Game_t& Game() {
		static Game_t instance;
		return instance;

	}

}
