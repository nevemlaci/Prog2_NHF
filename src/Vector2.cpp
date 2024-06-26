// Vector2.cpp

#include "Vector2.hpp"
#include <cmath>

#ifndef CPORTA

#endif

namespace SGL2 {
	Vector2::Vector2(double x , double y) : x(x), y(y) {}

	double Vector2::abs() const {
		return sqrt((x * x) + (y * y));
	}

	double Vector2::length() const {
		return this->abs();
	}

	Vector2 Vector2::normalized() const
	{
		if (abs() == 0) return Vector2(0, 0);
		return Vector2(x / abs(), y / abs());
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

	double Vector2::operator*(const Vector2& other) const{
		return (this->x * other.x + this->y * other.y);
	}


	Vector2 Vector2::operator*(double m) const{
		return Vector2(x * m, y * m);
	}

	Vector2& Vector2::operator*=(double m) {
		(*this) = Vector2(x * m, y * m);
		return (*this);
	}

#ifndef CPORTA

#endif

#ifdef CPORTA
	
#endif

	Vector2 operator*(double m , const Vector2& r) {
		return Vector2(r.x * m, r.y * m);
	}

}
