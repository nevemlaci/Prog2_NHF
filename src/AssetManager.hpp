// AssetManager.hpp

#ifndef __AssetManager_H__
#define __AssetManager_H__

#ifndef CPORTA

#include <cpp_SDL_include.hpp>
#include <string>
#include <map>
#include <memory>

namespace SGE2 {

class AssetManager {
	friend class Game;
public:

	void AddFont(const std::string& asset_name, const std::string& font_path, unsigned int fontsize = 14);

	SDL::Font& GetFont(const std::string& asset_name) const;
	
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

	}

	void AddSound(const std::string& asset_name, const std::string& path);
	
	const SDL::MixChunk& GetSound(const std::string& asset_name) const;

private:
	AssetManager(Game* game);
	std::map<std::string, std::unique_ptr<SDL::Texture>> m_Textures;
	std::map<std::string, std::unique_ptr<SDL::Font>> m_Fonts;
	Game& m_RootGameRef;
	
};
}
#endif
#endif


