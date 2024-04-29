// RendererComponent.cpp
#ifndef CPORTA

#include "RendererComponent.hpp"
#include "Game.hpp"
#include "GameObject.hpp"



namespace SGL2 {
	RendererComponent::RendererComponent(GameObject& root, 
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

	void RendererComponent::Startup(Game& game)  {
		std::cout << "\tAdded RendererComponent(id: " << m_Id << ") to " << m_RootGameObject.GetId() << '\n';
	}

	void RendererComponent::Update(Game& game) {
		game.GetRenderer() << SDL::at({ 
			m_RootGameObject.transform.position.x + m_OffsetX - game.GetMainCamera().transform.position.x,
			m_RootGameObject.transform.position.y + m_OffsetY - game.GetMainCamera().transform.position.y,
			m_RootGameObject.transform.size.x * m_ScaleX * game.GetMainCamera().transform.size.x/game.GetScreenSize().x,
			m_RootGameObject.transform.size.y * m_ScaleY * game.GetMainCamera().transform.size.y / game.GetScreenSize().y })
			<< m_Texture;
	}

}

#endif
