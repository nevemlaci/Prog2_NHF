#include "Game.hpp"
#include "AssetManager.hpp"
#include <iostream>

#ifndef CPORTA

namespace SGE2 {
	AssetManager::AssetManager(Game* game) : m_RootGameRef(*game), m_Music(nullptr)
	{

	}

	AssetManager::~AssetManager()
	{
		for (auto m : m_Fonts) {
			delete m.second;
		}
		for (auto m : m_Textures) {
			delete m.second;
		}
		for (auto m : m_Texts) {
			delete m.second;
		}
		delete m_Music;
	}
	
	void AssetManager::AddFont(const std::string& asset_name, const std::string& font_path, unsigned int fontsize)
	{
		m_Fonts[asset_name] = new SDL::Font(font_path.c_str(), fontsize);
	}

	const SDL::Font& AssetManager::GetFont(const std::string& asset_name) const
	{
		return (*m_Fonts.at(asset_name));
	}
	
	void AssetManager::AddText(
		const std::string& asset_name, 
		const std::string& text, 
		const std::string& font_asset_name, 
		SDL_Color color)
	{
		try {
			m_Texts[asset_name] = new SDL::Text(
				text.c_str(),
				*m_Fonts[font_asset_name],
				m_RootGameRef.GetRenderer(),
				color);
		}
		catch (const char* e) {
			std::cout << e << '\n';
		}
	}

	const SDL::Text& AssetManager::GetText(const std::string& asset_name) const
	{
		return (*m_Texts.at(asset_name));
	}

	void AssetManager::AddTexture(const std::string& asset_name, const std::string& path)
	{
		try {
			m_Textures[asset_name] = new SDL::Texture(path.c_str(), m_RootGameRef.GetRenderer());
		}
		catch (const char* e) {
			std::cout << e << '\n';
		}
	}

	const SDL::Texture& AssetManager::GetTexture(const std::string& asset_name) const
	{
		return (*m_Textures.at(asset_name));
	}

	void AssetManager::SetMusic(const std::string& path)
	{
		try {
		m_Music = new SDL::MixMusic(path.c_str());
		}
		catch (const char* e) {
			std::cout << e << '\n';
		}
	}
	
	void AssetManager::AddSound(const std::string& asset_name, const std::string& path)
	{
		try {
			m_SFXs[asset_name] = new SDL::MixChunk(path.c_str());
		}
		catch (const char* e) {
			std::cout << e << '\n';
		}
	}
	const SDL::MixChunk& AssetManager::GetSound(const std::string& asset_name) const
	{
		return (*m_SFXs.at(asset_name));
	}
}
#endif