#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>


class GameObjects
{
public:
    GameObjects(std::string);
    void showShape()const;

private:
    std::string m_textureFile;

};