// GameObject.cpp

#include "GameObject.hpp"
#include "Game.hpp"
#ifndef CPORTA

#endif

namespace SGL2 {
#ifndef CPORTA
	GameObject::GameObject(
		const std::string& id,
		const Vector2& position, 
		const Vector2& size,
		float rot
	) :
		transform({ position, size, rot }),
		m_Id(id),
		m_IsActive(true)
	{
		std::cout << "New GameObject added. Id: " << m_Id << '\n';
	}


#endif

#ifdef CPORTA
	GameObject::GameObject(
		Game_t& root_game, 
		const std::string& id,
		const Vector2& position,
		const Vector2& size,
		float rot) : 
		transform({ position, size, rot }),
		m_Id(id),
		m_RootGameRef(root_game),
		m_IsActive(true)
	{}

#endif

	bool GameObject::Active() const {
		return m_IsActive;
	}

	void GameObject::Active(bool a) {
		m_IsActive = a;
	}

	GameObject::~GameObject() {
		
	}
}
