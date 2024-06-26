// Camera.hpp

#ifndef __Camera_H__
#define __Camera_H__

#ifndef CPORTA

#include "cpp_SDL_include.hpp"
#include "Vector2.hpp"
#include "GameObject.hpp"



namespace SGL2 {
	/// @brief Camera
	class Camera final : public GameObject {
		friend class Game_t;
	public:
	private:
		Camera(const Vector2& position, const Vector2& size);
		Camera& operator=(const Camera& other);
	};
}
#endif
#endif


