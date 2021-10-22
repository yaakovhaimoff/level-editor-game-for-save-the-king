#include "Square.h"
#include "Rectangle.h"
#include "Vertex.h"
#include "Board.h"

#include <iostream>
#include <cmath>

#pragma once
#include <iosfwd>

Square::Square(const Vertex &bottomLeft, const Vertex &topRight)
{
   if (m_bottomLeft.isHigherThan(m_topRight) ||
        m_bottomLeft.isToTheRightOf(m_topRight) ||
        !m_bottomLeft.isValid() || !m_topRight.isValid()||
        (abs(m_bottomLeft.m_row - m_topRight.m_row) >= 0.5))
    {
        m_bottomLeft = Vertex(20, 10);
        m_topRight = Vertex(30, 20);
    }
}

Square::Square(const Vertex &start, double length)
{
    m_topRight.m_col = length + m_bottomLeft.m_row;
    m_topRight.m_row = length + m_bottomLeft.m_col;
    Rectangle(start, m_topRight);
}

Vertex Square::getBottomLeft(const double leftBottomVertex)
{

}

Vertex Square::getTopRight(const double rightTopVertex)
{

}

Vertex Square::getTopLength(const double topLength)
{

}
