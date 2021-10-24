#pragma once

#include "Hourglass.h"
#include "Vertex.h"
#include "Triangle.h"
#include "Board.h"
#include "Utilities.h"
#include <cmath>

// ________________________________________
Hourglass::Hourglass(const Triangle &upper,
                     const Triangle &lower)
{
}
// ________________________________________
Hourglass::Hourglass(const Triangle &lower)
{
}
// ________________________________
double Hourglass::getLength() const
{
}
// _________________________________
double Hourglass::getHeight() const
{
}

// _____________________________________
void Hourglass::draw(Board &board) const
{
}
// ______________________________________________
Rectangle Hourglass::getBoundingRectangle() const
{
}
// ______________________________
double Hourglass::getArea() const
{
}
// ___________________________________
double Hourglass::getPerimeter() const
{
}
// ________________________________
Vertex Hourglass::getCenter() const
{
}
// _________________________________
bool Hourglass::scale(double factor)
{
}