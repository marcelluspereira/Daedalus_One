/*****************************************************************//**
 * \file   tilemap.hpp
 * \brief  Header file for the TileMap class
 *
 * \author Marcellus Pereira <marcellus.pereira@gmail.com>
 * \date   March 2025
 *********************************************************************/

#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <filesystem>

namespace daedalus::tilemap
{
    class TileMap : public sf::Drawable, public sf::Transformable
    {
    public:
        bool load(const std::filesystem::path& tileset, sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height);

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        sf::VertexArray m_vertices;
        sf::Texture     m_tileset;
    };
}

