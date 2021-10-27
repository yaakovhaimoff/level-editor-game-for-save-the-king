#include <iostream>
#include "Square.h"

// _____________________________________________________________
Square::Square(const Vertex &bottomLeft, const Vertex &topRight)
    : m_square(bottomLeft, topRight)
{
    if (doubleEqual(distance(bottomLeft, Vertex(topRight.m_col, bottomLeft.m_row)),
                    distance(Vertex(topRight.m_col, bottomLeft.m_row), topRight)))
    {
        m_square = Rectangle(Vertex(20, 10), Vertex(30, 20));
    }
}
// _______________________________________________
Square::Square(const Vertex &start, double length)
    : m_square(start, Vertex(length + start.m_row,
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
    return m_square.scale(factor);
}