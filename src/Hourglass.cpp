#include <iostream>
#include "Hourglass.h"
Triangle defLower = Triangle(Vertex(20, 20), Vertex(30, 20), sqrt(75));
Triangle defUpper = Triangle(Vertex(20, 20 + (2 * sqrt(75))), Vertex(30, 20 + 2 * sqrt(75)),
                             -sqrt(75));
// ________________________________________
Hourglass::Hourglass(const Triangle &upper,
                     const Triangle &lower)
    : m_bottomTriangle(lower), m_topTriangle(upper)
{
    if (!isHourglass(upper, lower))
    {
        setValues();
    }
}
// ________________________________________
Hourglass::Hourglass(const Triangle &lower)
    : m_bottomTriangle(defLower),
      m_topTriangle(defUpper)
{
    Triangle newUpper(Vertex(lower.getVertex(0).m_col, 2 * lower.getHeight()),
                      Vertex(lower.getVertex(1).m_col, 2 * lower.getHeight()),
                      -(lower.getHeight()));
    if (isHourglass(newUpper, lower))
    {
        m_topTriangle = newUpper;
        m_bottomTriangle = lower;
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
                     m_topTriangle.getVertex(1));
}
// ______________________________
double Hourglass::getArea() const
{
    return 2 * m_bottomTriangle.getArea();
}
// ___________________________________
double Hourglass::getPerimeter() const
{
    return 2 * m_bottomTriangle.getPerimeter();
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
    scaleHourglass(m_bottomTriangle, factor);
    scaleHourglass(m_topTriangle, factor);
    if (factor < 0 || !isHourglass(m_bottomTriangle, m_topTriangle))
    {
        return false;
    }
    return true;
}
// ______________________________________________
bool Hourglass::isHourglass(const Triangle &upper,
                            const Triangle &lower) const
{
    return isUpperAndLower(upper, lower) && isVertexShared(upper, lower) &&
           isLengthSame(upper, lower);
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
// ________________________
void Hourglass::setValues()
{
    m_bottomTriangle = defLower;
    m_topTriangle = defUpper;
}
void Hourglass::scaleHourglass(Triangle &t, double factor)
{
    Vertex newV0, newV1, newV2, center = getCenter();
    newV0 = Vertex((center.m_col - (center.m_col - t.getVertex(0).m_col) * factor),
                   (center.m_row - (center.m_row - t.getVertex(0).m_row) * factor));
    newV1 = Vertex((center.m_col - (center.m_col - t.getVertex(1).m_col) * factor),
                   (center.m_row - (center.m_row - t.getVertex(1).m_row) * factor));
    newV2 = Vertex((center.m_col - (center.m_col - t.getVertex(2).m_col) * factor),
                   (center.m_row - (center.m_row - t.getVertex(2).m_row) * factor));
    t.getVertex(0) = newV0;
    t.getVertex(1) = newV1;
    t.getVertex(2) = newV2;
}
