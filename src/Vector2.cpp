// Vector2.cpp

#include "Vector2.hpp"
#include <cmath>

#ifndef CPORTA

#endif

namespace SGE2 {
	Vector2::Vector2(float x , float y) : x(x), y(y) {}

	float Vector2::abs() const {
		return sqrtf((x * x) + (y * y));
	}

	Vector2 Vector2::operator+(const Vector2& other) const{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2& Vector2::operator+=(const Vector2& other) {
		(*this) = (*this) + other;
		return (*this);
	}

	Vector2 Vector2::operator-(const Vector2& other) const{
		return Vector2(x - other.x, y - other.y);
	}
	Vector2& Vector2::operator-=(const Vector2& other) {
		(*this) = (*this) - other;
		return (*this);
	}

	float Vector2::operator*(const Vector2& other) const{
		return (this->x * other.x + this->y * other.y);
	}


	Vector2 Vector2::operator*(float m) const{
		return Vector2(x * m, y * m);
	}

	Vector2& Vector2::operator*=(float m) {
		(*this) = Vector2(x * m, y * m);
		return (*this);
	}

#ifndef CPORTA

#endif

#ifdef CPORTA
	
#endif

	Vector2 operator*(float m , const Vector2& r) {
		return Vector2(r.x * m, r.y * m);
	}

}
