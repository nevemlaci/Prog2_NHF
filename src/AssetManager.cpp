#include "AssetManager.hpp"

#include "Game.hpp"

namespace SGE2 {

	AssetManager::AssetManager(Game* game) : m_RootGameRef(*game)
	{

	}
	
	void AssetManager::AddFont(const std::string& asset_name, const std::string& font_path, unsigned int fontsize)
	{
		m_Fonts[asset_name] = std::make_unique<SDL::Font>(font_path.c_str(), fontsize);
	}
	
	void AssetManager::AddText(
		const std::string& asset_name, 
		const std::string& text, 
		const std::string& font_asset_name, 
		SDL_Color color)
	{
		m_Textures[asset_name] = std::make_unique<SDL::Text>(
			text.c_str(),
			*m_Fonts[font_asset_name],
			m_RootGameRef.GetRenderer(),
			color);
	}

	void AssetManager::AddTexture(const std::string& asset_name, const std::string& path)
	{
		m_Textures[asset_name] = std::make_unique<SDL::Texture>(path.c_str(), m_RootGameRef.GetRenderer());
	}
}
