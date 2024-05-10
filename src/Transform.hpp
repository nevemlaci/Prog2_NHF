// Transform.hpp

#ifndef __Transform_H__
#define __Transform_H__

#include "Vector2.hpp"

#ifndef CPORTA

#endif

#include "memtrace.h"


namespace SGL2 {
struct Transform final {
public:
	Vector2 position;
	Vector2 size;
	float rotation;

	Vector2 Middle() const;
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


