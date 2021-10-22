#pragma once

#include <iosfwd>
#include "Vertex.h"
#include "Board.h"
#include "Triangle.h"
#include "Utilities.h"
#include <cmath>


Triangle::Triangle(const Vertex vertcies[3])
{
    if (!vertcies[0].isValid() || !vertcies[1].isValid() ||
        !vertcies[3].isValid() ||
        doubleEqual(vertcies[0].m_row, vertcies[1].m_row) ||
        doubleEqual(vertcies[0].m_row, vertcies[2].m_row))
    {
        m_triangleVertex[0] = Vertex(20, 20);
        m_triangleVertex[1] = Vertex(30, 20);
        m_triangleVertex[2] = Vertex(25, 20 + sqrt(75));
    }
}

Triangle::Triangle(const Vertex &v0,
                   const Vertex &v1, double height):
                   Triangle()
{
    m_triangleVertex[0] = Vertex(v0.m_col, v0.m_row);
    m_triangleVertex[1] = Vertex(v0.m_col, v0.m_row);
    m_triangleVertex[2].m_col = abs(v0.m_col - v1.m_col);
    v0.m_col > v1.m_col ? m_triangleVertex[2].m_col += v1.m_col
                        : m_triangleVertex[2].m_col += v0.m_col;
    m_triangleVertex[2].m_row = m_triangleVertex[2].m_col + height;
    
    Triangle(m_triangleVertex[]);
}

Vertex Triangle::getVertex(int index) const
{
    return m_triangleVertex[index];
}

double Triangle::getLength() const
{
    return abs(m_triangleVertex[1].m_col - m_triangleVertex[0].m_col);
}

double Triangle::getHeight() const
{
    return abs(m_triangleVertex[2].m_row-m_triangleVertex[1].m_row);
}