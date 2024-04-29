// Transform.hpp

#ifndef __Transform_H__
#define __Transform_H__

#include "Vector2.hpp"

#ifndef CPORTA

#endif

#include "memtrace.h"

//MyTodo: should add a middle point to transforms
namespace SGL2 {
struct Transform final {
public:
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


