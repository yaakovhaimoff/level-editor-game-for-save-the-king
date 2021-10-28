#include "Hourglass.h"

Triangle defLower(Vertex(20, 20), Vertex(30, 20), sqrt(75));
Triangle defUpper(Vertex(20, 20 + (2 * sqrt(75))), Vertex(30, 20 + 2 * sqrt(75)),
                  sqrt(75));

// ________________________________________
Hourglass::Hourglass(const Triangle &upper, const Triangle &lower)
    : m_topTriangle(upper), m_bottomTriangle(lower)
{
    if (!isHourglass(upper, lower))
    {
        setValues();
    }
}
// ________________________________________
Hourglass::Hourglass(const Triangle &lower)
    : m_bottomTriangle(lower), m_topTriangle(Vertex(lower.getVertex(0).m_col, lower.getVertex(0).m_row + lower.getHeight()),
                      Vertex(lower.getVertex(1).m_col, lower.getVertex(0).m_row + lower.getHeight()),
                      -(lower.getHeight()))
{
    if (!isHourglass(m_topTriangle, m_bottomTriangle))
    {
        setValues();
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
    return 2 * m_topTriangle.getLength();
}
// _____________________________________
void Hourglass::draw(Board &board) const
{
    m_topTriangle.draw(board);
    m_bottomTriangle.draw(board);
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
// sending each triangle and scaling him by him self with
// hourglass center.
// _________________________________
bool Hourglass::scale(double factor)
{
    scaleHourglass(m_bottomTriangle, factor);
    scaleHourglass(m_topTriangle, factor);

    if (factor < 0 || !m_bottomTriangle.getVertex(0).isValid() ||
        !m_topTriangle.getVertex(1).isValid())
    {
        return false;
    }
    return true;
}
// checking for hourglass requirements
// ______________________________________________
bool Hourglass::isHourglass(const Triangle &upper,
                            const Triangle &lower) 
{
    return isUpperAndLower(upper, lower) && isVertexShared(upper, lower) &&
           isLengthSame(upper, lower);
}
// __________________________________________________
bool Hourglass::isUpperAndLower(const Triangle &upper,
                                const Triangle &lower) 
{
    return upper.getVertex(0).isHigherThan(upper.getVertex(2)) &&
           lower.getVertex(2).isHigherThan(lower.getVertex(0));
}
// __________________________________________________
bool Hourglass::isVertexShared(const Triangle &upper,
                               const Triangle &lower)
{
    return doubleEqual(upper.getVertex(2).m_col, lower.getVertex(2).m_col) &&
           doubleEqual(upper.getVertex(2).m_row, lower.getVertex(2).m_row);
}
// __________________________________________________
bool Hourglass::isLengthSame(const Triangle &upper,
                             const Triangle &lower)
{
    return doubleEqual(distance(upper.getVertex(0), upper.getVertex(1)),
                       distance(lower.getVertex(0), lower.getVertex(1)));
}
// setting the values for the default triangle in case of
// unvalid insert by the user coordinates.
// ________________________
void Hourglass::setValues()
{
    m_bottomTriangle = defLower;
    m_topTriangle = defUpper;
}
//_______________________________________________________
void Hourglass::scaleHourglass(Triangle &t, double factor)
{
    Vertex newTriangle[3], center = getCenter();
    newTriangle[0] = Vertex(center.m_col - ((center.m_col - t.getVertex(0).m_col) * factor),
                            center.m_row - ((center.m_row - t.getVertex(0).m_row) * factor));
    newTriangle[1] = Vertex(center.m_col - ((center.m_col - t.getVertex(1).m_col) * factor),
                            center.m_row - ((center.m_row - t.getVertex(1).m_row) * factor));
    newTriangle[2] = center;
    t = newTriangle;
}
