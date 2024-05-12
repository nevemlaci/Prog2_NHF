// Transform.hpp

#ifndef __Transform_H__
#define __Transform_H__

#include "Vector2.hpp"

#ifndef CPORTA

#endif

#include "memtrace.h"


namespace SGL2 {
/// @brief represents a GameObject's transformations in 2d space(position, size, rotation)
struct Transform final {
public:
	Vector2 position;
	Vector2 size;
	float rotation;

	/// @brief calculates the middle point of the transform
	/// @return middle point of the transform
	Vector2 Middle() const;
	/// @brief Sets the position of the transform by moving it's middle point instead of the top left point
	/// @param middlepos: position of the middle point
	void SetPositionByMiddle(const Vector2& middlepos);
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
}
#endif


