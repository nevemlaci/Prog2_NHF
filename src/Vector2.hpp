// Vector2.hpp

#ifndef __Vector2_H__
#define __Vector2_H__

#ifndef CPORTA

#endif

#include "memtrace.h"

namespace SGL2 {
/// @brief Represents a vector in 2d space
class Vector2 {
public:
	double x;
	double y;

	Vector2(double x = 0, double y = 0);

	/// @brief length of the vector
	double abs() const;

	/// @brief length of the vector
	double length() const;

	/// @brief normalizes the vector(divides both coordinates by the vector's lenght
	Vector2 normalized() const;

	Vector2 operator+(const Vector2&) const;
	Vector2& operator+=(const Vector2&);

	Vector2 operator-(const Vector2&) const;
	Vector2& operator-=(const Vector2&);

	double operator*(const Vector2&) const;

	Vector2 operator*(double) const;
	Vector2& operator*=(double);
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif

private:
#ifndef CPORTA

#endif

#ifdef CPORTA

#endif
};

Vector2 operator*(double, const Vector2&);
	
}
#endif


