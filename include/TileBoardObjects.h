#pragma once 

#include "GameObjects.h"
#include "macros.h"

//___________________________________
class WallObject : public GameObjects
{
public:
	WallObject();

};

//_____________________________________
class CrownObject : public GameObjects
{
public:
	CrownObject();

};

//___________________________________
class FireObject : public GameObjects
{
public:
	FireObject();

};

//____________________________________
class GateObject : public GameObjects
{
public:
	GateObject();

};

//___________________________________
class KeyeObject : public GameObjects
{
public:
	KeyeObject();

};

//______________________________________
class MonsterObject : public GameObjects
{
public:
	MonsterObject();

};

//_________________________________________
class TeleporterObject : public GameObjects
{
public:
	TeleporterObject();

};
