#include <iostream>
#include "Square.h"

// call rectangle constructor to build
// and then check
// _____________________________________________________________
Square::Square(const Vertex &bottomLeft, const Vertex &topRight)
{
    if (isQuad(bottomLeft, topRight) &&
        (doubleEqual(bottomLeft.m_col, topRight.m_col) &&
         doubleEqual(bottomLeft.m_row, topRight.m_row)))
    {
        m_square.getBottomLeft() = bottomLeft;
        m_square.getTopRight() = topRight;
    }
    else
    {
        m_square.getBottomLeft() = Vertex(20, 10);
        m_square.getTopRight() = Vertex(30, 20);
    }
}
// _______________________________________________
Square::Square(const Vertex &start, double length)
    : Square(start, Vertex(length + start.m_row,
                           length + start.m_col)) {}
// ________________________________________________________
Vertex Square::getBottomLeft() const
{
    return m_square.getBottomLeft();
}
// _____________________________________________________
Vertex Square::getTopRight() const
{
    return m_square.getTopRight();
}
// _____________________________________________
double Square::getLength() const
{
    return abs(m_square.getBottomLeft().m_col - m_square.getTopRight().m_col);
}
// __________________________________
void Square::draw(Board &board) const
{
    m_square.draw(board);
}
// ___________________________________________
Rectangle Square::getBoundingRectangle() const
{
    return Rectangle(m_square.getBottomLeft(), m_square.getTopRight());
}
// ___________________________
double Square::getArea() const
{
    return m_square.getArea();
}
// ___________________________________
double Square::getPerimeter() const
{
    return m_square.getPerimeter();
}
// ______________________________
Vertex Square::getCenter() const
{
    return m_square.getCenter();
}
// ______________________________
bool Square::scale(double factor)
{
    m_square.scale(factor);
}
// _________________________________________
bool Square::isQuad(const Vertex v1, const Vertex v2) const
{
    return v1.isHigherThan(v2) &&
           v1.isToTheRightOf(v2) &&
           v1.isValid() && v2.isValid();
}