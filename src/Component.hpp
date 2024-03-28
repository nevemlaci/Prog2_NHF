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
	Component(GameObject*);
	
	virtual void Startup(Game&);
	virtual void Update(Game&);

	const char* GetId() { return m_Id; }
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif

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


