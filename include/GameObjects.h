#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>


class GameObjects
{
public:
    GameObjects(std::string);
    void showShape(sf::RenderWindow&)const;
    void setLocation(const int, const int);


private:
    std::string m_textureFile;
    std::vector <sf::Vector2f> m_locations;

};