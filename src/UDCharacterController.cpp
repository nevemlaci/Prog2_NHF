#include "UDCharacterController.hpp"
#include "GameObject.hpp"

namespace SGE2 {
	UDCharacterController::UDCharacterController(GameObject& gameobject, const std::string& id) :
		Component(gameobject, id)
	{}

	void UDCharacterController::Move(const Vector2 vec)
	{
		m_MoveAmount = vec;
		m_ShouldMove = true;
	}

	void UDCharacterController::Rotate(float rot)
	{
		m_RotAmount = rot;
		m_ShouldRotate = true;
	}

	void UDCharacterController::Startup(Game& game)
	{}

	void UDCharacterController::Update(Game & game)
	{
		if (m_ShouldMove) DoMove();
		if (m_ShouldRotate) DoRotate();
	}

	void UDCharacterController::DoMove()
	{
		m_RootGameObject.transform.position += m_MoveAmount;
		m_ShouldMove = false;
	}

	void UDCharacterController::DoRotate()
	{
		//ugly way to get rotation between 0-360
		m_RootGameObject.transform.rotation = (m_RootGameObject.transform.rotation + m_RotAmount) - ((static_cast<int>(m_RootGameObject.transform.rotation + m_RotAmount) / 360) *360 );
		m_ShouldRotate = false;
	}

}




