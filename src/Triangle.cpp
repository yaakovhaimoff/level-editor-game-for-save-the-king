#include <iostream>
#include "Triangle.h"

Triangle::Triangle(const Vertex vertcies[3])
    : m_triangleVertex0(vertcies[0]), m_triangleVertex1(vertcies[1]), m_triangleVertex2(vertcies[2])
{
    if (!sameRow(vertcies[2], m_triangleVertex2))
    {
        m_triangleVertex0 = Vertex(20, 20);
        m_triangleVertex1 = Vertex(30, 20);
        m_triangleVertex2 = Vertex(25, 20 + sqrt(75));
    }
}
// __________________________________________________________________
Triangle::Triangle(const Vertex &v0, const Vertex &v1, double height)
    : m_triangleVertex0(v0), m_triangleVertex1(v1),
      m_triangleVertex2(Vertex((v0.m_col + v1.m_col) / 2, (v1.m_row + height)))
{
    // checking if the  new vertcies form a triangle
    if (!isTriangle(m_triangleVertex0, m_triangleVertex1, m_triangleVertex2))
    {
        m_triangleVertex0 = Vertex(20, 20);
        m_triangleVertex1 = Vertex(30, 20);
        m_triangleVertex2 = Vertex(25, 20 + sqrt(75));
    }
}
// getting a vertex by choice for further use
// _________________________________________
Vertex Triangle::getVertex(int index) const
{
    switch(index){
        case 0: return m_triangleVertex0;
        break;
        case 1: return m_triangleVertex1;
        break;
        case 2: m_triangleVertex2;
        break;
    }
}
// _______________________________
double Triangle::getLength() const
{
    return distance(m_triangleVertex0, m_triangleVertex1);
}
// _______________________________
double Triangle::getHeight() const
{
    return abs(m_triangleVertex2.m_row - m_triangleVertex1.m_row);
}
// _____________________________________
void Triangle::draw(Board &board) const
{
    board.drawLine(m_triangleVertex0, m_triangleVertex1);
    board.drawLine(m_triangleVertex1, m_triangleVertex2);
    board.drawLine(m_triangleVertex2, m_triangleVertex0);
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
    return Vertex((m_triangleVertex0.m_col + m_triangleVertex1.m_col +
                   m_triangleVertex2.m_col) /
                      3,
                  (m_triangleVertex0.m_row + m_triangleVertex1.m_row +
                   m_triangleVertex2.m_row) /
                      3);
}
// ________________________________
bool Triangle::scale(double factor)
{
    Vertex newV0, newV1, newV2, center = getCenter();
    newV0 = Vertex((center.m_col - (center.m_col - m_triangleVertex0.m_col) * factor),
                   (center.m_row - (center.m_row - m_triangleVertex0.m_row) * factor));
    newV1 = Vertex((center.m_col - (center.m_col - m_triangleVertex1.m_col) * factor),
                   (center.m_row - (center.m_row - m_triangleVertex1.m_row) * factor));
    newV2 = Vertex((center.m_col - (center.m_col - m_triangleVertex2.m_col) * factor),
                   (center.m_row - (center.m_row - m_triangleVertex2.m_row) * factor));
    if (factor < 0 || !isTriangle(newV0, newV1, newV2))
    {
        return false;
    }
    m_triangleVertex0 = newV0;
    m_triangleVertex1 = newV1;
    m_triangleVertex2 = newV2;
    return true;
}
// ______________________________________________
Vertex Triangle::getLeftVertexForBounding() const
{
    if (m_triangleVertex2.isHigherThan(m_triangleVertex0))
    {
        return m_triangleVertex0;
    }
    return Vertex(m_triangleVertex0.m_col, m_triangleVertex2.m_row);
}
// ______________________________________________
Vertex Triangle::getRightVertexForBounding() const
{
    if (m_triangleVertex2.isHigherThan(m_triangleVertex0))
    {
        return Vertex(m_triangleVertex1.m_col, m_triangleVertex2.m_row);
    }
    return m_triangleVertex1;
}
// _______________________________________________________________________________
bool Triangle::isTriangle(const Vertex v0, const Vertex v1, const Vertex v2) const
{
    return isTriangleLengthValid(v0, v1, v2) && isTriangleVertexValid(v0, v1, v2) &&
           sameRow(v0, v1);
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
