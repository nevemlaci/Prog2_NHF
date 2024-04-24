#include "Camera.hpp"

#ifndef CPORTA


namespace SGL2 {

	Camera::Camera(Game& root_game, const Vector2& position, const Vector2& size) : GameObject(root_game, "MainCamera", position, size, 0)
	{}

	Camera& SGL2::Camera::operator=(const Camera & other)
	{
		this->transform = other.transform;
		return (*this);
	}
}
#endif
