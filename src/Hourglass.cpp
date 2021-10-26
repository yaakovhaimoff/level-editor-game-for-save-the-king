#include <iostream>
#include "Hourglass.h"
/*
// ________________________________________
Hourglass::Hourglass(const Triangle &upper,
                     const Triangle &lower)
    : m_topTriangle(upper), m_bottomTriangle(lower)
{
    if (!isHourglass(m_topTriangle, m_bottomTriangle))
    {
        Triangle(Vertex(20, 20), Vertex(30, 20), 20 + sqrtf(75));
        Triangle(Vertex(25, 20 + sqrt(75)), Vertex(20, 20 + 2 * sqrt(75)),
                 20 + 2 * sqrt(75));
    }
}
// ________________________________________
Hourglass::Hourglass(const Triangle &lower) :
    m_topTriangle(lower), m_topTriangle(Vertex(lower.getVertex(0).m_col, 2 * distance(lower.getVertex(0), lower.getVertex(2))),
    Vertex(lower.getVertex(1).m_col,2 * distance(lower.getVertex(0), lower.getVertex(2))), lower.getVertex(2))
{
    // newUpper.getVertex(0).m_col = lower.getVertex(0).m_col;
    // newUpper.getVertex(0).m_row = 2 * distance(lower.getVertex(0), lower.getVertex(2));
    // newUpper.getVertex(1).m_col = lower.getVertex(1).m_col;
    // newUpper.getVertex(1).m_row = 2 * distance(lower.getVertex(0), lower.getVertex(2));
    // newUpper.getVertex(2) = lower.getVertex(2);
    if (isHourglass(newUpper, lower))
    {
        m_bottomTriangle = lower;
        m_topTriangle = newUpper;
    }
    else
    {
        Triangle(Vertex(20, 20), Vertex(30, 20), 20 + sqrtf(75));
        Triangle(Vertex(25, 20 + sqrt(75)), Vertex(20, 20 + 2 * sqrt(75)),
                 20 + 2 * sqrt(75));
    }
}
// ________________________________
double Hourglass::getLength() const
{
    return m_bottomTriangle.getLength();
}
// _________________________________
double Hourglass::getHeight() const
{
    return m_topTriangle.getLength() +
           m_bottomTriangle.getHeight();
}
// _____________________________________
void Hourglass::draw(Board &board) const
{
    this->m_bottomTriangle.draw(board);
    this->m_topTriangle.draw(board);
}
// ______________________________________________
Rectangle Hourglass::getBoundingRectangle() const
{
    return Rectangle(m_bottomTriangle.getVertex(0),
                     Vertex(m_topTriangle.getVertex(1)));
}
// ______________________________
double Hourglass::getArea() const
{
    return this->m_bottomTriangle.getArea() +
           this->m_topTriangle.getArea();
}
// ___________________________________
double Hourglass::getPerimeter() const
{
    return this->m_bottomTriangle.getPerimeter() +
           this->m_topTriangle.getPerimeter();
}
// to get the center i'll calculate the average of cols between
// both of the triangle, and the average beetween the rows as well.
// ________________________________
Vertex Hourglass::getCenter() const
{
    return Vertex((this->m_bottomTriangle.getCenter().m_col +
                   this->m_topTriangle.getCenter().m_col) /
                      2,
                  (this->m_bottomTriangle.getCenter().m_row +
                   this->m_topTriangle.getCenter().m_row) /
                      2);
}
// _________________________________
bool Hourglass::scale(double factor)
{
    m_bottomTriangle.scale(factor);
    m_topTriangle.scale(factor);
}
bool Hourglass::isHourglass(const Triangle &upper,
                            const Triangle &lower) const
{
    return isUpperAndLower(upper, lower) &&
           isVertexShared(upper, lower) && isLengthSame(upper, lower);
}
// __________________________________________________
bool Hourglass::isUpperAndLower(const Triangle &upper,
                                const Triangle &lower) const
{
    return upper.getVertex(0).isHigherThan(upper.getVertex(2)) &&
           lower.getVertex(2).isHigherThan(lower.getVertex(0));
}
// __________________________________________________
bool Hourglass::isVertexShared(const Triangle &upper,
                               const Triangle &lower) const
{
    return doubleEqual(upper.getVertex(3).m_col, lower.getVertex(3).m_col) &&
           doubleEqual(upper.getVertex(3).m_row, lower.getVertex(3).m_row);
}
// __________________________________________________
bool Hourglass::isLengthSame(const Triangle &upper,
                             const Triangle &lower) const
{
    return doubleEqual(distance(upper.getVertex(0), upper.getVertex(1)),
                       distance(lower.getVertex(0), lower.getVertex(1)));
}
*/