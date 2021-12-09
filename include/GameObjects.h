#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>


class GameObjects
{
public:
    GameObjects(std::string, int, int, char);
    void showShape(sf::RenderWindow&)const;
    void setLocation(sf::Vector2f&);
    int getAmountOfLocation()const;


private:
    char m_key;
    sf::Texture m_textureFile;
    std::vector <sf::Vector2f> m_locations;

};