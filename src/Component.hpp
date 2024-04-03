// Component.hpp

#ifndef __Component_H__
#define __Component_H__

#ifndef CPORTA

#endif

namespace SGE2 {
	class GameObject;
	class Game;

class Component {
public:
	Component(GameObject*, const char*);
	
	virtual void Startup(Game&) = 0;
	virtual void Update(Game&) = 0;

	const char* GetId() { return m_Id; }
	GameObject& GetRoot() { return (*m_RootGameObject); }
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif

private:

protected:
	GameObject* m_RootGameObject;
	const char* m_Id;
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif
};
}
#endif


