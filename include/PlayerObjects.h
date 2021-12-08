#pragma once 

#include "GameObjects.h"

class PlayerObjects : public GameObjects
{
public:
	PlayerObjects();

private:
	std::vector <sf::Vector2f> m_locations;
};