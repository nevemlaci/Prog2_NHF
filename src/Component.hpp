// Component.hpp

#ifndef __Component_H__
#define __Component_H__

#include <string>

#ifndef CPORTA

#endif

namespace SGE2 {
	class GameObject;
	class Game;

class Component {
public:
	Component(
		GameObject& gameobject, 
		const std::string& id
	);

	virtual ~Component() {}
	
	virtual void Startup(Game& game) = 0;
	virtual void Update(Game& game) = 0;

	const std::string& GetId() { return m_Id; }
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif

private:

protected:
	GameObject& m_RootGameObject;
	std::string m_Id;
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif
};
}
#endif


