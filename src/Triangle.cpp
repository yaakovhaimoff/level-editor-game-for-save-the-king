#include <iostream>
#include "Triangle.h"

Triangle::Triangle(const Vertex vertcies[3])
    : Triangle(vertcies[0], vertcies[1], vertcies[2].m_row - vertcies[1].m_row)
{
    if (!sameCol(vertcies[2], m_triangleVertex[2]))
    {
        m_triangleVertex[0] = Vertex(20, 20);
        m_triangleVertex[1] = Vertex(30, 20);
        m_triangleVertex[2] = Vertex(25, 20 + sqrt(75));
    }
}
// ________________________________________________
Triangle::Triangle(const Vertex &v0, const Vertex &v1, double height)
{
    Vertex v2;
    // calculating the third vertex of the triangle
    v2.m_col = (v0.m_col + v1.m_col) / 2;
    v2.m_row = (v1.m_row + height);
    // checking if the  new vertcies form a triangle
    // check hourGlass
    if (isTriangle(v0, v1, v2))
    {
        m_triangleVertex[0] = v0;
        m_triangleVertex[1] = v1;
        m_triangleVertex[2] = v2;
    }
    // default triangle in of invalidate triangle from the user
    else
    {
        m_triangleVertex[0] = Vertex(20, 20);
        m_triangleVertex[1] = Vertex(30, 20);
        m_triangleVertex[2] = Vertex(25, 20 + sqrt(75));
    }
}
// getting a vertex by choice for further use
// _________________________________________
Vertex Triangle::getVertex(int index) const
{
    return m_triangleVertex[index];
}
// _______________________________
double Triangle::getLength() const
{
    return distance(m_triangleVertex[0], m_triangleVertex[1]);
}
// _______________________________
double Triangle::getHeight() const
{
    return abs(m_triangleVertex[2].m_row - m_triangleVertex[1].m_row);
}
// _____________________________________
void Triangle::draw(Board &board) const
{
    board.drawLine(m_triangleVertex[0], m_triangleVertex[1]);
    board.drawLine(m_triangleVertex[1], m_triangleVertex[2]);
    board.drawLine(m_triangleVertex[2], m_triangleVertex[0]);
}

// _____________________________________________
Rectangle Triangle::getBoundingRectangle() const
{
    return Rectangle(getLeftVertexForBounding(), getRightVertexForBounding());
}
// ______________________________
double Triangle::getArea() const
{
    return (getLength() * getHeight()) / 2;
}
// __________________________________
double Triangle::getPerimeter() const
{
    return 3 * getLength();
}
// _______________________________
Vertex Triangle::getCenter() const
{
    return Vertex((m_triangleVertex[0].m_col + m_triangleVertex[1].m_col +
                   m_triangleVertex[2].m_col) /
                      3,
                  (m_triangleVertex[0].m_row + m_triangleVertex[1].m_row +
                   m_triangleVertex[2].m_row) /
                      3);
}
// ________________________________
bool Triangle::scale(double factor)
{
    Vertex newV0, newV1, newV2, center = getCenter();
    newV0 = Vertex((center.m_col - (center.m_col - m_triangleVertex[0].m_col) * factor),
                   (center.m_row - (center.m_row - m_triangleVertex[0].m_row) * factor));
    newV1 = Vertex((center.m_col - (center.m_col - m_triangleVertex[1].m_col) * factor),
                   (center.m_row - (center.m_row - m_triangleVertex[1].m_row) * factor));
    newV2 = Vertex((center.m_col - (center.m_col - m_triangleVertex[2].m_col) * factor),
                   (center.m_row - (center.m_row - m_triangleVertex[2].m_row) * factor));
    if (factor < 0 || !isTriangle(newV0, newV1, newV2))
    {
        return false;
    }
    m_triangleVertex[0] = newV0;
    m_triangleVertex[1] = newV1;
    m_triangleVertex[2] = newV2;
    return true;
}
// ______________________________________________
Vertex Triangle::getLeftVertexForBounding() const
{
    if (m_triangleVertex[2].isHigherThan(m_triangleVertex[0]))
    {
        return m_triangleVertex[0];
    }
    return Vertex(m_triangleVertex[0].m_col, m_triangleVertex[2].m_row);
}
// ______________________________________________
Vertex Triangle::getRightVertexForBounding() const
{
    if (m_triangleVertex[2].isHigherThan(m_triangleVertex[0]))
    {
        return Vertex(m_triangleVertex[1].m_col, m_triangleVertex[2].m_row);
    }
    return m_triangleVertex[1];
}
// _______________________________________________________________________________
bool Triangle::isTriangle(const Vertex v0, const Vertex v1, const Vertex v2) const
{
    return isTriangleLengthValid(v0, v1, v2) && isTriangleVertexValid(v0, v1, v2) &&
           sameCol(v0, v1);
}
// _________________________________________________________________________________________
bool Triangle::isTriangleVertexValid(const Vertex v0, const Vertex v1, const Vertex v2) const
{
    return v0.isValid() && v1.isValid() &&
           v2.isValid();
}
// __________________________________________________________________________________________
bool Triangle::isTriangleLengthValid(const Vertex v0, const Vertex v1, const Vertex v2) const
{
    return doubleEqual(distance(v0, v1), distance(v1, v2)) &&
           doubleEqual(distance(v0, v1), distance(v0, v2));
}
