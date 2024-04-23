// GameObject.cpp

#include "GameObject.hpp"
#include "Game.hpp"
#ifndef CPORTA

#endif

namespace SGE2 {
#ifndef CPORTA
	GameObject::GameObject(
		Game& root_game,
		const std::string& id,
		const Vector2&
		position, const
		Vector2& size,
		float rot
	) :
		transform({ position, size, rot }),
		m_Id(id),
		m_RootGameRef(root_game),
		m_IsActive(true)
	{
		std::cout << "New GameObject added. Id: " << m_Id << '\n';
	}


#endif

#ifdef CPORTA
	GameObject::GameObject(
		Game& root_game, 
		const std::string& id,
		const Vector2& position,
		const Vector2& size,
		float rot) : 
		m_Id(id),
		m_RootGameRef(root_game),
		m_IsActive(true),
		transform({ position, size, rot })
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
