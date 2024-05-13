// RendererComponent.cpp
#ifndef CPORTA

#include "RendererComponent.hpp"
#include "Game.hpp"
#include "GameObject.hpp"



namespace SGL2 {
	RendererComponent::RendererComponent(GameObject& root, 
		const std::string& id, 
		const std::string& asset_name,
		double scaleX, double scaleY,
		double offsetX, double offsety) :
		Component(root, id),
		m_OffsetX(offsetX),
		m_OffsetY(offsety),
		m_ScaleX(scaleX),
		m_ScaleY(scaleY),
		m_Texture(AssetManager().GetTexture(asset_name)) 
	{}

	void RendererComponent::Startup()  {
		std::cout << "\tAdded RendererComponent(id: " << m_Id << ") to " << m_RootGameObject.GetId() << '\n';
	}

	void RendererComponent::Update() {
		Game().GetRenderer() << SDL::at({
			m_RootGameObject.transform.position.x + m_OffsetX - Game().GetMainCamera().transform.position.x,
			m_RootGameObject.transform.position.y + m_OffsetY - Game().GetMainCamera().transform.position.y,
			m_RootGameObject.transform.size.x * m_ScaleX * Game().GetMainCamera().transform.size.x/Game().GetScreenSize().x,
			m_RootGameObject.transform.size.y * m_ScaleY * Game().GetMainCamera().transform.size.y / Game().GetScreenSize().y })
			<< m_Texture;
	}

}

#endif
