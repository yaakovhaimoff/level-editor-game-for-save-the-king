#include <iostream>
#include "Hourglass.h"
// delete out and vs
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
Hourglass::Hourglass(const Triangle &lower)
{
    Vertex newUpper[3];
    newUpper[0].m_col = lower.getVertex(0).m_col;
    newUpper[0].m_row = 2 * distance(lower.getVertex(0), lower.getVertex(2));
    newUpper[1].m_col = lower.getVertex(1).m_col;
    newUpper[1].m_row = 2 * distance(lower.getVertex(0), lower.getVertex(2));
    newUpper[2] = lower.getVertex(2);
    if (isUpperValid(newUpper))
    {
        m_topTriangle.getVertex(0)= Vertex(lower.getVertex(0).m_col,2 * distance(lower.getVertex(0), lower.getVertex(2)));
        m_topTriangle.getVertex(1) = Vertex(lower.getVertex(1).m_col, 2 * distance(lower.getVertex(0), lower.getVertex(2)));
        m_topTriangle.getVertex(2) = lower.getVertex(2);
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
    m_bottomTriangle.draw(board);
    m_topTriangle.draw(board);
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
    return m_bottomTriangle.getArea() +
           m_topTriangle.getArea();
}
// ___________________________________
double Hourglass::getPerimeter() const
{
    return m_bottomTriangle.getPerimeter() +
           m_topTriangle.getPerimeter();
}
// to get the center i'll calculate the average of cols between
// both of the triangle, and the average beetween the rows as well.
// ________________________________
Vertex Hourglass::getCenter() const
{
    return m_bottomTriangle.getVertex(2);
}
// _________________________________
bool Hourglass::scale(double factor)
{
   return  m_bottomTriangle.scale(factor) && m_topTriangle.scale(factor);
}
// ______________________________________________
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
    return doubleEqual(upper.getVertex(2).m_col, lower.getVertex(2).m_col) &&
           doubleEqual(upper.getVertex(2).m_row, lower.getVertex(2).m_row);
}
// __________________________________________________
bool Hourglass::isLengthSame(const Triangle &upper,
                             const Triangle &lower) const
{
    return doubleEqual(distance(upper.getVertex(0), upper.getVertex(1)),
                       distance(lower.getVertex(0), lower.getVertex(1)));
}
// ________________________________________________
bool Hourglass::isUpperValid(Vertex upper[3]) const
{
    return upper[0].isValid() && upper[1].isValid() && upper[2].isValid();
}
