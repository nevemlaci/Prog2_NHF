// AssetManager.hpp

#ifndef __AssetManager_H__
#define __AssetManager_H__

#ifndef CPORTA

#include <cpp_SDL_include.hpp>
#include <string>
#include <map>
#include <memory>

#include "memtrace.h"

namespace SGL2 {

	class Game_t;
class AssetManager_t {
	friend AssetManager_t& AssetManager();
public:

	void AddFont(const std::string& asset_name, const std::string& font_path, unsigned int fontsize = 14);

	const SDL::Font& GetFont(const std::string& asset_name) const;
	
	void AddText(
		const std::string& asset_name,
		const std::string& text,
		const std::string& font_asset_name,
		SDL_Color color = { 0, 0, 0, 255 });

	const SDL::Text& GetText(const std::string& asset_name) const;

	void AddTexture(const std::string& asset_name, const std::string& path);
	
	const SDL::Texture& GetTexture(const std::string& asset_name) const;

	void SetMusic(const std::string& path);
	
	const SDL::MixMusic& GetMusic() const {
		return (*m_Music);
	}

	void AddSound(const std::string& asset_name, const std::string& path);
	
	const SDL::MixChunk& GetSound(const std::string& asset_name) const;
private:
	AssetManager_t(Game_t* game);
	std::map<std::string, std::unique_ptr<SDL::Texture>> m_Textures;
	std::map<std::string, std::unique_ptr<SDL::Text>> m_Texts;
	std::map<std::string, std::unique_ptr<SDL::Font>> m_Fonts;

	SDL::MixMusic* m_Music;
	std::map<std::string, std::unique_ptr<SDL::MixChunk>> m_SFXs;


	Game_t& m_RootGameRef;
	
};

AssetManager_t& AssetManager();
}
#endif
#endif


