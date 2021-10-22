#include "Rectangle.h"
#include "Vertex.h"

#include <iostream>
#include <cmath>

#pragma once
#include <iosfwd>

Rectangle::Rectangle(const Vertex &bottomLeft, const Vertex &topRight)
{
    if (m_bottomLeft.isHigherThan(m_rightTop) ||
        m_bottomLeft.isToTheRightOf(m_rightTop) ||
        !m_bottomLeft.isValid() || !m_rightTop.isValid())
    {
        m_bottomLeft = Vertex(20, 10);
        m_rightTop = Vertex(30, 20);
    }
}

Rectangle::Rectangle(const Vertex vertices[2])
{
    Rectangle(vertices[0], vertices[1]);
}

Rectangle::Rectangle(const Vertex &start, double width, double height)
{
    m_rightTop.m_col = width + m_bottomLeft.m_row;
    m_rightTop.m_row = height + m_bottomLeft.m_col;
    Rectangle(start, m_rightTop);
}

Rectangle::Rectangle(double x0, double y0, double x1, double y1)
{
    Rectangle(Vertex(x0, y0), Vertex(x1, y1));
}

Vertex Rectangle::getBottomLeft() const
{
    return m_bottomLeft;
}
Vertex Rectangle::getTopRight() const
{
    return m_rightTop;
}

double Rectangle::getHeight() const
{
    return abs(m_rightTop.m_row - m_bottomLeft.m_row);
}

double Rectangle::getWidth() const
{
    return abs(m_rightTop.m_col + m_bottomLeft.m_col);
}