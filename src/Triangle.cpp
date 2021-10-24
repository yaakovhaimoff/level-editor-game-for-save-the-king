#pragma once

#include <iosfwd>
#include "Vertex.h"
#include "Board.h"
#include "Triangle.h"
#include "Utilities.h"
#include <cmath>

// _________________________________________
Triangle::Triangle(const Vertex vertcies[3])
{
    if (vertcies[0].isTriangle(vertcies[1], vertcies[2]) &&
        sameCol(vertcies[0], vertcies[1]))
    {
        m_triangleVertex[0] = vertcies[0];
        m_triangleVertex[1] = vertcies[1];
        m_triangleVertex[2] = vertcies[2];
    }
    else
    {
        m_triangleVertex[0] = Vertex(20, 20);
        m_triangleVertex[1] = Vertex(30, 20);
        m_triangleVertex[2] = Vertex(25, 20 + sqrt(75));
    }
}
// ________________________________________________
Triangle::Triangle(const Vertex &v0, const Vertex &v1, double height)
    : Rectangle(v0, v1, Vertex((v0.m_col + v1.m_col) / 2, v1.m_row + height)) {}
// _________________________________________
Vertex Triangle::getVertex(int index) const
{
    return m_triangleVertex[index];
}
// _______________________________
double Triangle::getLength() const
{
    return abs(m_triangleVertex[1].m_col - m_triangleVertex[0].m_col);
}
// _______________________________
double Triangle::getHeight() const
{
    return abs(m_triangleVertex[2].m_row - m_triangleVertex[1].m_row);
}

// not good, need to work on it more.
// _____________________________________
void Triangle::draw(Board &board) const
{
    board.drawLine(m_triangleVertex[0], m_triangleVertex[1]);
}

// _____________________________________________
Rectangle Triangle::getBoundingRectangle() const
{
}
// ______________________________
double Triangle::getArea() const
{
    return (abs(m_triangleVertex[0].m_col - m_triangleVertex[1].m_col) *
            abs(m_triangleVertex[2].m_row - m_triangleVertex[1].m_row)) /
           2;
}
// __________________________________
double Triangle::getPerimeter() const
{
    return 3 *
           abs(m_triangleVertex[0].m_col - m_triangleVertex[1].m_col);
}
// _______________________________
Vertex Triangle::getCenter() const
{
    return Vertex((abs(m_triangleVertex[0].m_col + m_triangleVertex[1].m_col)) / 2,
                  (abs(m_triangleVertex[0].m_row + m_triangleVertex[1].m_row)) / 2);
}
// ________________________________
bool Triangle::scale(double factor)
{
}