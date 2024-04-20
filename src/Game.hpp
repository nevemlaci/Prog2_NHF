// Game.hpp

#ifndef __Game_H__
#define __Game_H__

#ifndef CPORTA
#include <cpp_SDL_include.hpp>
#endif

#include <vector>
#include <memory>

#include "GameObject.hpp"
#include "AssetManager.hpp"

namespace SGE2 {
class Game final {
	friend class GameObject;
	friend class AssetManager;
public:
	/// @brief game instance ctor
	/// @param title title of the game(and the game window)
	Game(const char* title);

	/// @brief runs the game
	void Run();
#ifndef CPORTA

	/// @brief getter for m_Renderer
	/// @return SDL::Renderer reference
	SDL::Renderer& GetRenderer() { return m_Renderer; }

	/// @brief getter for m_Window
	/// @return SDL::Window reference
	SDL::Window& GetWindow() { return m_Window; }
#endif

#ifdef CPORTA
	/// @brief (only for cporta debug) 
	/// @return returns the reference to the gameobject ptr vector
	std::vector<std::unique_ptr<GameObject>>& GetGameObjectVector() {
		return m_GameObjects;
	}
#endif

	/// @brief 
	/// @return title of the game 
	const char* GetTitle() const { return m_Title; }

	/// @brief adds a game object of type T with ...args being passed to the constructor
	/// @tparam T should inherit from GameObject. Type of the object to be added(specifies what ctor is called)
	/// @tparam ...Args should not be passed explicitly
	/// @param ...args arguments to be passed into T's constructor
	/// @return returns a reference to the newly added GameObject
	template<typename T, class... Args>
	T& AddGameObject(Args&&... args) {
		m_GameObjects.push_back(std::make_unique<T>((*this), std::forward<Args>(args)...));
		return dynamic_cast<T&>(*m_GameObjects.back());
	}

	/// @brief getter for game objects based on type and id
	/// @tparam T type of gameobject(also specifies the type of the return value
	/// @param id 
	/// @return returns a reference to the gameobject(T&) if found
	/// @exception throws std::runtime_error if an appropriate gameobject was not found.
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

	/// @brief deletes a gameobject with given id
	/// @param id 
	void DeleteGameObject(const std::string& id);

private:
#ifndef CPORTA
	/// @brief Runs the main loop of the game
	void MainLoop();
#endif

#ifndef CPORTA
	SDL::SDL& m_SDL;
	SDL::Window m_Window;
	SDL::Renderer m_Renderer;

	AssetManager m_AssetManager;
#endif



	std::vector<std::unique_ptr<GameObject>> m_GameObjects;

	const char* m_Title;

#ifdef CPORTA

#endif
};
}
#endif


