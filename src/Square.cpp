#pragma once

#include "Square.h"
#include "Rectangle.h"
#include "Vertex.h"
#include "Board.h"
#include "Utilities.h"

#include <iostream>
#include <cmath>
#include <iosfwd>

Square::Square(const Vertex &bottomLeft, const Vertex &topRight)
{
    if (bottomLeft.isQuad(topRight) ||
        (abs(bottomLeft.m_col - topRight.m_col) -
             abs(bottomLeft.m_row - topRight.m_row) >
         0.5))
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

Square::Square(const Vertex &start, double length)
    : Square(start, Vertex(length + m_bottomLeft.m_row, length + m_bottomLeft.m_col))
{
}

Vertex Square::getBottomLeft(const double leftBottomVertex)
{
    return m_bottomLeft;
}

Vertex Square::getTopRight(const double rightTopVertex)
{
    return m_topRight;
}

Vertex Square::getTopLength(const double topLength)
{
}
