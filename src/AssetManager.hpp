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
/// @brief Manages text, fonts, textures and sounds
class AssetManager_t {
	friend AssetManager_t& AssetManager();
public:
	/// @brief Loads a new font
	/// @param asset_name name of the asset(used to reference it via the library)
	/// @param font_path path to the font file
	/// @param fontsize the size the font should be loaded with
	void AddFont(const std::string& asset_name, const std::string& font_path, unsigned int fontsize = 14);

	//MyTodo: add try-catch to getters for not-found cases

	/// @brief 
	/// @param asset_name 
	/// @return SDL::Font reference to the font
	const SDL::Font& GetFont(const std::string& asset_name) const;
	
	/// @brief Loads a text with a given font
	/// @param asset_name name of the asset(used to reference it via the library)
	/// @param text 
	/// @param font_asset_name name of the font asset
	/// @param color color of the text, black by default. Format: {red, green, blue, alpha}
	void AddText(
		const std::string& asset_name,
		const std::string& text,
		const std::string& font_asset_name,
		SDL_Color color = { 0, 0, 0, 255 });

	/// @brief 
	/// @param asset_name 
	/// @return SDL::Text reference to the text object
	const SDL::Text& GetText(const std::string& asset_name) const;

	/// @brief Loads a texture
	/// @param asset_name name of the asset(used to reference it via the library)
	/// @param path path to the texture(image) file
	void AddTexture(const std::string& asset_name, const std::string& path);
	
	/// @brief 
	/// @param asset_name 
	/// @return SDL::Texture reference to the texture object
	const SDL::Texture& GetTexture(const std::string& asset_name) const;

	/// @brief set the music of the game. Only one music can be loaded at one time.
	/// @param path path to the music file
	void SetMusic(const std::string& path);
	
	/// @brief 
	/// @return SDL::MixMusic reference to the music object 
	const SDL::MixMusic& GetMusic() const {
		return (*m_Music);
	}

	/// @brief Loads a sound
	/// @param asset_name name of the asset(used to reference it via the library)
	/// @param path path to the sound file
	void AddSound(const std::string& asset_name, const std::string& path);
	
	/// @brief 
	/// @param asset_name 
	/// @return SDL::MixChunk reference to thesound object
	const SDL::MixChunk& GetSound(const std::string& asset_name) const;
private:
	//MyTodo : init SDL_MIXER inside this ctor
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


