// Transform.hpp

#ifndef __Transform_H__
#define __Transform_H__

#include "memtrace.h"

#include "Vector2.hpp"

#ifndef CPORTA

#endif

namespace SGE2 {
class Transform {
public:
	friend class GameObject;
	Vector2 position;
	Vector2 size;
	float rotation;
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


