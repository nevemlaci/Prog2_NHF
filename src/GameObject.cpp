// GameObject.cpp

#include "GameObject.hpp"

#ifndef CPORTA

#endif

namespace SGE2 {
#ifndef CPORTA
	GameObject::GameObject(Game& root_game, const char* id, const Vector2& position, const Vector2& size, float rot) :
		m_Id(id),
		m_RootGameRef(root_game),
		transform({position, size, rot })
	{}

	GameObject::~GameObject() {}

#endif

#ifdef CPORTA
	GameObject::GameObject(const Vector2& position, const Vector2& size, float rot)
	{
		m_Transform.position = position;
		m_Transform.size = size;
		m_Transform.rot = rot;
	}
#endif

}
