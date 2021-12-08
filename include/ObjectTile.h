#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>


class ObjectTile
{
public:
    void showShape()const;

private:
    std::string m_textureFile;
    char m_key;
    sf::Texture m_texture;
    std::vector <sf::Vector2f> m_locations;

};