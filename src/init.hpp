// init.hpp

#ifndef __init_H__
#define __init_H__
#include "Game.hpp"
#include "GameObject.hpp"
#include "Component.hpp"

#ifndef CPORTA
#undef main //sdl2 magic
#endif

namespace SGE2 {
	Game* init();
}
#endif


