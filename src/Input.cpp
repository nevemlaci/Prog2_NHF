#include "Input.hpp"
#include "Game.hpp"

#ifndef CPORTA
SGL2::InputManager::InputManager(Game& root_game) :
	m_RootGameRef(root_game)
{}

void SGL2::InputManager::AddMacro(const std::string& macro_name, const char* key_name){
	m_InputMacros[macro_name] = (SDL_GetScancodeFromName(key_name));
}

bool SGL2::InputManager::Get(const std::string& macro_name)
{
	if (m_RootGameRef.GetSDL().CheckKey(m_InputMacros[macro_name])) {
		return true;
	}
	return false;
}

#endif