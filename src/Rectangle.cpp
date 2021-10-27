#pragma once

#include "Rectangle.h"

// ____________________________________________________________________
Rectangle::Rectangle(const Vertex &bottomLeft, const Vertex &topRight)
{
    if (isQuad(topRight, bottomLeft))
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
    return abs(m_topRight.m_col - m_bottomLeft.m_col);
}
// _____________________________________
void Rectangle::draw(Board &board) const
{
    board.drawLine(m_bottomLeft,
                   Vertex(m_topRight.m_col, m_bottomLeft.m_row));
    board.drawLine(Vertex(m_topRight.m_col, m_bottomLeft.m_row),
                   m_topRight);
    board.drawLine(m_topRight, Vertex(m_bottomLeft.m_col,
                                      m_topRight.m_row));
    board.drawLine(Vertex(m_bottomLeft.m_col, m_topRight.m_row),
                   m_bottomLeft);
}
// _____________________________________________
Rectangle Rectangle::getBoundingRectangle() const
{
    return Rectangle(m_bottomLeft, m_topRight);
}
// ______________________________
double Rectangle::getArea() const
{
    return getHeight() * getWidth();
}
// ___________________________________
double Rectangle::getPerimeter() const
{
    return ((2 * getHeight()) + (2 * getWidth()));
}
// ________________________________
Vertex Rectangle::getCenter() const
{
    return Vertex((m_bottomLeft.m_col + m_topRight.m_col) / 2,
                  (m_bottomLeft.m_row + m_topRight.m_row) / 2);
}
// _________________________________
bool Rectangle::scale(double factor)
{
    Vertex newBottom, newTop, center = getCenter();
    newBottom = Vertex(center.m_col - ((center.m_col - m_bottomLeft.m_col) * factor),
                       (center.m_row - (center.m_row - m_bottomLeft.m_row) * factor));
    newTop = Vertex(center.m_col - ((center.m_col - newBottom.m_col) * factor),
                    (center.m_row - (center.m_row - newBottom.m_row) * factor));

    if (factor < 0 || isQuad(newBottom, newTop))
    {
        return false;
    }
    m_bottomLeft = newBottom;
    m_topRight = newTop;
    return true;
}
// _________________________________________
bool Rectangle::isQuad(const Vertex topRight, const Vertex bottomLeft) const
{
    return topRight.isHigherThan(bottomLeft) &&
           topRight.isToTheRightOf(bottomLeft) &&
           topRight.isValid() && bottomLeft.isValid();
}