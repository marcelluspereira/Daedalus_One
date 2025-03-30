/**
*/

#pragma once

#include "tileson.hpp"
#include "SFML/Graphics.hpp"
#include <map>
#include <cstdint>

namespace daedalus::map_manager {

	class MapManager
	{
	public:
		MapManager() {};

		bool initialize(sf::RenderWindow* window, const fs::path& basePath = fs::path("assets/maps/"));
		std::unique_ptr<tson::Map> parseMap(const std::string& filename = "ultimate_test.json", std::unique_ptr<tson::IDecompressor<std::vector<uint8_t>, std::vector<uint8_t>>> decompressor = nullptr);
		bool parseProject(const std::string& filename = "test.tiled-project");
		void run();

	private:
		void drawMap();

		void drawLayer(tson::Layer& layer);
		void drawTileLayer(tson::Layer& layer);//, tson::Tileset* tileset);
		void drawImageLayer(tson::Layer& layer);
		void drawObjectLayer(tson::Layer& layer);
		void drawTexture(const sf::Texture& texture, const sf::IntRect& textureRegion, const sf::Vector2f& position,
			int32_t tileHeight, bool hortFlip, bool vertFlip, bool diagonalFlip);

		sf::Vector2f getTileOffset(int tileId, tson::Map* map, tson::Tileset* tileset);


		const sf::Texture* getTexture(const std::string& image);
		sf::Sprite* storeAndLoadImage(const std::string& image, const sf::Vector2f& position);
		template <typename T>
		fs::path getImagePath(const T& tileset);
		void updateAnimations();

		sf::RenderWindow* m_window;

		fs::path m_basePath{};
		std::unique_ptr<tson::Map> m_map;
		std::unique_ptr<tson::Map> m_imageCollectionTilesetMap;
		std::unique_ptr<tson::Map> m_marginSpaceMap;

		std::map<std::string, std::unique_ptr<tson::Map>> m_projectMaps; //Non-world maps in project

		std::vector<std::unique_ptr<tson::Map>> m_worldMaps; //World-related maps in project
		std::vector<tson::WorldMapData> m_worldData; //World-related data in project
		std::vector<bool> m_worldVisibilityFlags; //World-related data in project
		std::vector<std::string> m_worldMapInfo;
		std::vector<std::string> m_projectMapInfo;

		tson::Map* m_currentMap;
		std::string m_currentInfo;
		tson::Project m_project;
		int m_mapIndex{ 0 };
		const int m_maxMapIndex{ 5 };

		sf::Time m_timeDelta;

		sf::Font m_font;

		tson::Vector2i m_positionOffset{ 0,0 }; //Used for world related stuff

		std::map<std::string, std::unique_ptr<sf::Texture>> m_textures;
		std::map<std::string, std::unique_ptr<sf::Sprite>> m_sprites;
		std::map<uint32_t, tson::Animation*> m_animationUpdateQueue;
	};
};

