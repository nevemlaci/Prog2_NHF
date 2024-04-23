// UDCharacterController.hpp

#ifndef __UDCharacterController_H__
#define __UDCharacterController_H__

#ifndef CPORTA

#include "Component.hpp"
#include "Vector2.hpp"

namespace SGE2 {
class UDCharacterController : public Component {
public:
	UDCharacterController(GameObject& gameobject, const std::string& id);
	void Move(const Vector2 vec);
	void Rotate(float rot);

	void Startup(Game& game);
	void Update(Game& game);
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


