#include "Game.hpp"
#include "AssetManager.hpp"
#include <iostream>

#ifndef CPORTA

namespace SGL2 {
	AssetManager_t::AssetManager_t(Game_t* game) : m_RootGameRef(*game), m_Music(nullptr)
	{
		if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_WEBP) == 0) 
			throw std::runtime_error(IMG_GetError());
		if (Mix_Init(MIX_INIT_OGG | MIX_INIT_MP3) == 0) 
			throw std::runtime_error(Mix_GetError());
		if (TTF_Init() == -1) throw std::runtime_error( TTF_GetError());

		SDL::Mixer::OpenAudio(16000, MIX_DEFAULT_FORMAT, 2, 512);
	}
	
	void AssetManager_t::AddFont(const std::string& asset_name, const std::string& font_path, unsigned int fontsize)
	{
		m_Fonts[asset_name] = std::make_unique<SDL::Font>(font_path.c_str(), fontsize);
	}

	const SDL::Font& AssetManager_t::GetFont(const std::string& asset_name) const
	{
		try {
			return (*m_Fonts.at(asset_name));
		}
		catch (std::out_of_range e) {
			throw std::out_of_range(std::string("Font with asset name: ") + asset_name + std::string(" was not found."));
		}


		return (*m_Fonts.at(asset_name));
	}
	
	void AssetManager_t::AddText(
		const std::string& asset_name, 
		const std::string& text, 
		const std::string& font_asset_name, 
		SDL_Color color)
	{
		try {
			m_Texts[asset_name] = std::make_unique<SDL::Text>(
				text.c_str(),
				*m_Fonts[font_asset_name],
				m_RootGameRef.GetRenderer(),
				color);
		}
		catch (const char* e) {
			std::cout << e << '\n';
		}
	}

	const SDL::Text& AssetManager_t::GetText(const std::string& asset_name) const
	{
		try {
			return (*m_Texts.at(asset_name));
		}
		catch (std::out_of_range e) {
			throw std::out_of_range(std::string("Text with asset name: ") + asset_name + std::string(" was not found."));
		}
		
	}

	void AssetManager_t::AddTexture(const std::string& asset_name, const std::string& path)
	{
		try {
			m_Textures[asset_name] = std::make_unique<SDL::Texture>(path.c_str(), m_RootGameRef.GetRenderer());
		}
		catch (const char* e) {
			std::cout << e << '\n';
		}
	}

	const SDL::Texture& AssetManager_t::GetTexture(const std::string& asset_name) const
	{
		try {
			return (*m_Textures.at(asset_name));
		}
		catch (std::out_of_range e) {
			throw std::out_of_range(std::string("Texture with asset name: ") + asset_name + std::string(" was not found."));
		}
	}

	void AssetManager_t::SetMusic(const std::string& path)
	{
		try {
		m_Music = new SDL::MixMusic(path.c_str());
		}
		catch (const char* e) {
			std::cout << e << '\n';
		}
	}
	
	void AssetManager_t::AddSound(const std::string& asset_name, const std::string& path)
	{
		try {
			m_SFXs[asset_name] = std::make_unique<SDL::MixChunk>(path.c_str());
		}
		catch (const char* e) {
			std::cout << e << '\n';
		}
	}
	const SDL::MixChunk& AssetManager_t::GetSound(const std::string& asset_name) const
	{
		try {
			return (*m_SFXs.at(asset_name));
		}
		catch (std::out_of_range e) {
			throw std::out_of_range(std::string("Sound with asset name: ") + asset_name + std::string(" was not found."));
		}
	}
	AssetManager_t& AssetManager() {
		static AssetManager_t instance(&Game());
		return instance;
	}
}
#endif