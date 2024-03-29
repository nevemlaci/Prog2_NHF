// GameObject.cpp

#include "GameObject.hpp"

#ifndef CPORTA

#endif

namespace SGE2 {
#ifndef CPORTA
	GameObject::GameObject(const Vector2& position, const Vector2& size, float rot) :
		m_Transform({ .position = position, .size = size, .rotation = rot })
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
