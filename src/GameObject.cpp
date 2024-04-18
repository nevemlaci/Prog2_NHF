// GameObject.cpp

#include "GameObject.hpp"

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
		m_Id(id),
		m_RootGameRef(root_game),
		transform({position, size, rot })
	{}


#endif

	GameObject::~GameObject() {}

#ifdef CPORTA
	GameObject::GameObject(
		Game& root_game,
		const std::string& id,
		const Vector2& position,
		const Vector2& size,
		float rot) : 
		m_RootGameRef(root_game),
		m_Id(id),
		transform({ position, size, rot })

	{}

#endif

}
