// Component.hpp

#ifndef __Component_H__
#define __Component_H__

#include <string>

#ifndef CPORTA

#endif

#include "memtrace.h"

namespace SGL2 {
	class GameObject;
	class Game_t;

class Component {
public:
	/// @brief Component ctor
	/// @param gameobject parent gameobject
	/// @param id 
	Component(
		GameObject& gameobject, 
		const std::string& id
	);

	virtual ~Component() {}
	
	/// @brief Runs after the component has been attached to the parent gameobject
	virtual void Startup() = 0;

	/// @brief Runs on every frame of the game
	virtual void Update() = 0;

	/// @brief getter for m_Id
	/// @return returns the id of the component
	const std::string& GetId() { return m_Id; }
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif

private:

protected:
	/// @brief reference to the parent gameobject
	GameObject& m_RootGameObject;
	/// @brief id of the component
	std::string m_Id;
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif
};
}
#endif


