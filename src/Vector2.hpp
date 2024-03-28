// Vector2.hpp

#ifndef __Vector2_H__
#define __Vector2_H__

#ifndef CPORTA

#endif

namespace SGE2 {
class Vector2 {
public:
	float x;
	float y;

	Vector2(int x = 0, int y = 0);

	float abs() const;

	Vector2 operator+(const Vector2&) const;
	Vector2& operator+=(const Vector2&);

	Vector2 operator-(const Vector2&) const;
	Vector2& operator-=(const Vector2&);

	float operator*(const Vector2&) const;

	Vector2 operator*(float) const;
	Vector2& operator*=(float);
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

Vector2 operator*(float, const Vector2&);
	
}
#endif


