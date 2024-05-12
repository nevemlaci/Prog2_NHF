// UDCharacterController.hpp

#ifndef __UDCharacterController_H__
#define __UDCharacterController_H__

#ifndef CPORTA

#include "Component.hpp"
#include "Vector2.hpp"

namespace SGL2 {
/// @brief Upside-down character controller. Allows for moving a game object with a vector.
class UDCharacterController : public Component {
public:
	/// @brief 
	/// @param gameobject 
	/// @param id 
	UDCharacterController(GameObject& gameobject, const std::string& id);

	/// @brief Moves the root with a vector
	/// @param vec the movement vector. Recommended to be normalized if used for player movement to prevent diagonal speed boost.
	void Move(const Vector2 vec);

	/// @brief Rotate the root
	/// @param rot amount of rotation(in degrees)
	void Rotate(float rot);


	void Startup(Game_t& game);
	void Update(Game_t& game);
private:
	void DoMove();
	void DoRotate();
	bool m_ShouldMove = false;
	Vector2 m_MoveAmount ;
	bool m_ShouldRotate = false;
	float m_RotAmount = 0;
};
}
#endif
#endif


