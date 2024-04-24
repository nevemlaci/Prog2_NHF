// Component.cpp

#include "Component.hpp"
#include "GameObject.hpp"

#ifndef CPORTA

#endif

namespace SGL2 {
	Component::Component(
		GameObject& gameobject, 
		const std::string& id
	) : 
		m_RootGameObject(gameobject), 
		m_Id(id) 
	{
		std::cout << "New component added to " << gameobject.GetId() << '\n';
	}
	

#ifndef CPORTA

#endif

#ifdef CPORTA
	
#endif

}
