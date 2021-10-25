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
    if (upper.)
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
    return m_topTriangle.getLength() +
           m_bottomTriangle.getHeight();
}
// _____________________________________
void Hourglass::draw(Board &board) const
{
    this->m_bottomTriangle.draw(board);
    this->m_topTriangle.draw(board);
}
// need to b finished
// ______________________________________________
Rectangle Hourglass::getBoundingRectangle() const
{
    return Rectangle(Vertex(), Vertex());
}
// ______________________________
double Hourglass::getArea() const
{
    return this->m_bottomTriangle.getArea() +
           this->m_topTriangle.getArea();
}
// ___________________________________
double Hourglass::getPerimeter() const
{
    return this->m_bottomTriangle.getPerimeter() +
           this->m_topTriangle.getPerimeter();
}
// ________________________________
Vertex Hourglass::getCenter() const
{
}
// _________________________________
bool Hourglass::scale(double factor)
{
}