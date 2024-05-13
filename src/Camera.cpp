#include "Camera.hpp"

#ifndef CPORTA


namespace SGL2 {

	Camera::Camera(const Vector2& position, const Vector2& size) : GameObject("MainCamera", position, size, 0)
	{}

	Camera& SGL2::Camera::operator=(const Camera & other)
	{
		this->transform = other.transform;
		return (*this);
	}
}
#endif
