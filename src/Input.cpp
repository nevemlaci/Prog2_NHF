#include "Input.hpp"
#include "Game.hpp"

#ifndef CPORTA

void SGL2::InputManager_t::AddMacro(const std::string& macro_name, const char* key_name){
	m_InputMacros[macro_name] = (SDL_GetScancodeFromName(key_name));
}

bool SGL2::InputManager_t::Get(const std::string& macro_name)
{
	if (Game().GetSDL().CheckKey(m_InputMacros[macro_name])) {
		return true;
	}
	return false;
}

SGL2::InputManager_t& SGL2::InputManager() {
	static InputManager_t instance;
	return instance;
}
#endif

