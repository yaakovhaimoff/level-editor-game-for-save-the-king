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
    if (m_bottomLeft.isQuad(m_bottomLeft, m_topRight))
    {
        m_bottomLeft = Vertex(20, 10);
        m_topRight = Vertex(30, 20);
    }
}
// ____________________________________________
Rectangle::Rectangle(const Vertex vertices[2])
    :Rectangle(vertices[0], vertices[1])
{}
// ____________________________________________________________________
Rectangle::Rectangle(const Vertex &start, double width, double height)
{
    m_topRight.m_col = width + m_bottomLeft.m_row;
    m_topRight.m_row = height + m_bottomLeft.m_col;
    Rectangle(start, m_topRight);
}
// _____________________________________________________________
Rectangle::Rectangle(double x0, double y0, double x1, double y1)
{
    Rectangle(Vertex(x0, y0), Vertex(x1, y1));
}
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