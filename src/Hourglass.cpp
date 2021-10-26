#pragma once

#include "Hourglass.h"
#include "Utilities.h"
#include <cmath>

// ________________________________________
Hourglass::Hourglass(const Triangle &upper,
                     const Triangle &lower)
{
    if (doubleEqual(upper.getLength(), lower.getLength()) &&
        upper.getVertex(3).m_col == lower.getVertex(3).m_col && upper.getVertex(3).m_row == lower.getVertex(3).m_row)
    {
        m_bottomTriangle = lower;
        m_topTriangle = upper;
    }
    else
    {
        Triangle(Vertex(20, 20), Vertex(30, 20), 20 + sqrtf(75));
        Triangle(Vertex(25, 20 + sqrt(75)), Vertex(20, 20 + 2 * sqrt(75)),
                 20 + 2 * sqrt(75));
    }
}
// ________________________________________
Hourglass::Hourglass(const Triangle &lower)
{
    if(lower){

    }
}
// ________________________________
double Hourglass::getLength() const
{
    return m_bottomTriangle.getLength();
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
// to get the center i'll calculate the average of cols between 
// both of the triangle, and the average beetween the rows as well.
// ________________________________
Vertex Hourglass::getCenter() const
{
    return Vertex((this->m_bottomTriangle.getCenter().m_col +
                   this->m_topTriangle.getCenter().m_col) /
                      2,
                  (this->m_bottomTriangle.getCenter().m_row +
                   this->m_topTriangle.getCenter().m_row) /
                      2);
}
// _________________________________
bool Hourglass::scale(double factor)
{
}