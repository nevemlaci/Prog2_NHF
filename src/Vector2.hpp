// Vector2.hpp

#ifndef __Vector2_H__
#define __Vector2_H__

#ifndef CPORTA

#endif

#include "memtrace.h"

namespace SGL2 {
class Vector2 {
public:
	double x;
	double y;

	Vector2(double x = 0, double y = 0);

	double abs() const;

	double length() const;

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


