#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>


class GameObjects
{
public:
    GameObjects(std::string, int, int, char);
    void showShape(sf::RenderWindow&)const;
    void setLocation(const int, const int);


private:
    char m_key;
    sf::Texture m_textureFile;
    std::vector <sf::Vector2f> m_locations;

};