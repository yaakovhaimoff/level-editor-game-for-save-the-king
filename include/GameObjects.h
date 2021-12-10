#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include "macros.h"

class GameObjects
{
public:
    GameObjects(std::string, int, int, char);
    void showShape(sf::RenderWindow&)const;
    void setLocation(sf::Vector2f&);
    int getAmountOfLocation()const;
    bool boardObjectExists(int, sf::Vector2f&);
    void eraseAllLocation();
    void eraseLocation(sf::Vector2f&);
    void saveBoardObjectsToVector(std::vector<std::vector<char>>&);

private:
    char m_key;
    sf::Texture m_textureFile;
    std::vector <sf::Vector2f> m_locations;

};