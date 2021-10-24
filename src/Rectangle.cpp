#pragma once

#include "Rectangle.h"
#include "Vertex.h"
#include "Board.h"
#include "Utilities.h"

#include <iostream>
#include <cmath>
#include <iosfwd>
// ____________________________________________________________________
Rectangle::Rectangle(const Vertex &bottomLeft, const Vertex &topRight)
{
    if (bottomLeft.isQuad(topRight))
    {
        m_bottomLeft = Vertex(20, 10);
        m_topRight = Vertex(30, 20);
    }
    else
    {
        m_bottomLeft = bottomLeft;
        m_topRight = topRight;
    }
}
// ____________________________________________
Rectangle::Rectangle(const Vertex vertices[2]) : Rectangle(vertices[0], vertices[1]) {}

// ____________________________________________________________________
Rectangle::Rectangle(const Vertex &start, double width, double height)
    : Rectangle(start, Vertex((width + start.m_col), (height + start.m_row))) {}
// _____________________________________________________________
Rectangle::Rectangle(double x0, double y0, double x1, double y1)
    : Rectangle(Vertex(x0, y0), Vertex(x1, y1)) {}

// ____________________________________
Vertex Rectangle::getBottomLeft() const
{
    return m_bottomLeft;
}
// __________________________________
Vertex Rectangle::getTopRight() const
{
    return m_topRight;
}
// ________________________________
double Rectangle::getHeight() const
{
    return abs(m_topRight.m_row - m_bottomLeft.m_row);
}
// _______________________________
double Rectangle::getWidth() const
{
    return abs(m_topRight.m_col + m_bottomLeft.m_col);
}
// _____________________________________
void Rectangle::draw(Board &board) const
{
    board.drawLine(m_bottomLeft, m_topRight);
}

// _____________________________________________
Rectangle Rectangle::getBoundingRectangle() const
{
}

// ______________________________
double Rectangle::getArea() const
{
    return abs(m_bottomLeft.m_col - m_topRight.m_col) *
           abs(m_bottomLeft.m_row - m_topRight.m_row);
}
double Rectangle::getPerimeter() const
{
    return (2 * abs(m_bottomLeft.m_col - m_topRight.m_col)) +
           (2 * abs(m_bottomLeft.m_row - m_topRight.m_row));
}

// ________________________________
Vertex Rectangle::getCenter() const
{
    return Vertex(abs(m_bottomLeft.m_col + m_topRight.m_col) / 2,
                  abs(m_bottomLeft.m_row + m_topRight.m_row) / 2);
}
// _________________________________
bool Rectangle::scale(double factor)
{
}