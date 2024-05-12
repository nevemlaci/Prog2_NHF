// Input.hpp

#ifndef __Input_H__
#define __Input_H__

#ifndef CPORTA //this should only exist when we are in a non console only environment
#include <cpp_SDL_include.hpp>
#include <map>
#include <vector>
#include <string>

namespace SGL2 {
class InputManager_t {
	friend InputManager_t& InputManager();
public:
	/// @brief Adds a new key to an input macro. If the macro does not exist it gets created
	/// @param macro_name 
	/// @param key_name Key name reference: https://wiki.libsdl.org/SDL2/SDL_ScancodeAndKeycode
	void AddMacro(const std::string& macro_name, const char* key_name);

	bool Get(const std::string& macro_name);

private:
	InputManager_t() = default;
	std::map<std::string, SDL_Scancode> m_InputMacros;

	
};

	InputManager_t& InputManager();
}
#endif
#endif


