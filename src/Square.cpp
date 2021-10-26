#pragma once

#include "Square.h"
#include "Rectangle.h"
#include "Vertex.h"
#include "Board.h"
#include "Utilities.h"

#include <iostream>
#include <cmath>
#include <iosfwd>
// _____________________________________________________________
Square::Square(const Vertex &bottomLeft, const Vertex &topRight)
{
    if (bottomLeft.isQuad(topRight) &&
        (doubleEqual(bottomLeft.m_col, topRight.m_col) &&
         doubleEqual(bottomLeft.m_row, topRight.m_row)))
    {
        m_bottomLeft = bottomLeft;
        m_topRight = topRight;
    }
    else
    {
        m_bottomLeft = Vertex(20, 10);
        m_topRight = Vertex(30, 20);
    }
}
// _______________________________________________
Square::Square(const Vertex &start, double length)
    : Square(start, Vertex(length + m_bottomLeft.m_row,
                           length + m_bottomLeft.m_col)) {}
// ________________________________________________________
Vertex Square::getBottomLeft(const double leftBottomVertex)
{
    return m_bottomLeft;
}
// _____________________________________________________
Vertex Square::getTopRight(const double rightTopVertex)
{
    return m_topRight;
}
// _____________________________________________
double Square::getLength(const double topLength)
{
    return abs(m_bottomLeft.m_col - m_topRight.m_col);
}
// __________________________________
void Square::draw(Board &board) const
{
    this->m_bottomLeft.drawQuad(board, this->m_topRight);
}
// ___________________________________________
Rectangle Square::getBoundingRectangle() const
{
    return Rectangle(this->m_bottomLeft, this->m_topRight);
}
// ___________________________
double Square::getArea() const
{
    return abs(this->m_bottomLeft.m_col - this->m_topRight.m_col) *
           abs(this->m_bottomLeft.m_row - this->m_topRight.m_row);
}
// ___________________________________
double Rectangle::getPerimeter() const
{
    return (2 * abs(this->m_bottomLeft.m_col - this->m_topRight.m_col)) +
           (2 * abs(this->m_bottomLeft.m_row - this->m_topRight.m_row));
}
// ______________________________
Vertex Square::getCenter() const
{
    return Vertex(abs(this->m_bottomLeft.m_col + this->m_topRight.m_col) / 2,
                  abs(this->m_bottomLeft.m_row + this->m_topRight.m_row) / 2);
}
// ______________________________
bool Square::scale(double factor)
{
     Vertex newBottom, newTop, center = getCenter();
    newBottom = Vertex((center.m_col - m_bottomLeft.m_col) * factor,
                       (center.m_row - m_bottomLeft.m_row) * factor);
    newTop = Vertex((center.m_col - newBottom.m_col) * factor,
                    (center.m_row - newBottom.m_row) * factor);
    // newBottom.m_col = (center.m_col - m_bottomLeft.m_col) * factor;
    // newBottom.m_row = (center.m_row - m_bottomLeft.m_row) * factor;
    // newTop.m_col = (center.m_col - m_topRight.m_col) * factor;
    // newTop.m_row = (center.m_row - m_topRight.m_row) * factor;

    if (factor < 0 || newBottom.isQuad(newTop))
    {
        return false;
    }
    m_bottomLeft = newBottom;
    m_topRight = newTop;
    return true;
}