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
    return this->m_bottomLeft;
}
// __________________________________
Vertex Rectangle::getTopRight() const
{
    return this->m_topRight;
}
// ________________________________
double Rectangle::getHeight() const
{
    return abs(this->m_topRight.m_row - this->m_bottomLeft.m_row);
}
// _______________________________
double Rectangle::getWidth() const
{
    return abs(this->m_topRight.m_col + this->m_bottomLeft.m_col);
}
// _____________________________________
void Rectangle::draw(Board &board) const
{
    board.drawLine(this->m_bottomLeft, Vertex(this->m_bottomLeft.m_row ,this->m_topRight.m_col));
    board.drawLine(Vertex(this->m_bottomLeft.m_row ,this->m_topRight.m_col), this->m_topRight);
    board.drawLine(this->m_topRight, Vertex(this->m_bottomLeft.m_col, this->m_topRight.m_row));
    board.drawLine(Vertex(this->m_bottomLeft.m_col, this->m_topRight.m_row), this->m_bottomLeft);
}

// _____________________________________________
Rectangle Rectangle::getBoundingRectangle() const
{
    return Rectangle(this->m_bottomLeft, this->m_topRight);
}
// ______________________________
double Rectangle::getArea() const
{
    return abs(this->m_bottomLeft.m_col - this->m_topRight.m_col) *
           abs(this->m_bottomLeft.m_row - this->m_topRight.m_row);
}
double Rectangle::getPerimeter() const
{
    return (2 * abs(this->m_bottomLeft.m_col - this->m_topRight.m_col)) +
           (2 * abs(this->m_bottomLeft.m_row - this->m_topRight.m_row));
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
    Vertex newBottom, newTop, center = getCenter();
    newBottom.m_col = (center.m_col - m_bottomLeft.m_col) * factor;
    newBottom.m_row = (center.m_row - m_bottomLeft.m_row) * factor;
    newTop.m_col = (center.m_col - newTop.m_col) * factor;
    newTop.m_row = (center.m_row - newTop.m_row) * factor;

    if (factor < 0 || newBottom.isQuad(newTop))
    {
        return false;
    }
    m_bottomLeft = newBottom;
    m_topRight = newTop;
    return true;
}