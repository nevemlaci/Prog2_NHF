#ifndef CPORTA

#include "WorldRendererComponent.hpp"
#include "Game.hpp"
#include "GameObject.hpp"



namespace SGL2 {
	WorldRendererComponent::WorldRendererComponent(GameObject& root,
		const std::string& id,
		const std::string& asset_name,
		int scaleX, int scaleY,
		int offsetX, int offsety) :
		Component(root, id),
		m_OffsetX(offsetX),
		m_OffsetY(offsety),
		m_ScaleX(scaleX),
		m_ScaleY(scaleY),
		m_Texture(root.GetRoot().GetAssetManager().GetTexture(asset_name))
	{}

	void WorldRendererComponent::Startup(Game& game) {
		std::cout << "\tAdded WorldRendererComponent(id: " << m_Id << ") to " << m_RootGameObject.GetId() << '\n';
	}

	void WorldRendererComponent::Update(Game& game) {
		game.GetRenderer() << SDL::at({
			m_RootGameObject.transform.position.x + m_OffsetX,
			m_RootGameObject.transform.position.y + m_OffsetY,
			m_RootGameObject.transform.size.x * m_ScaleX,
			m_RootGameObject.transform.size.y * m_ScaleY})
			<< m_Texture;
	}

}

#endif
