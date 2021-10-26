#include "Vertex.h"
#include "macros.h"
#include <iostream>

// _________________________________________________
bool Vertex::isHigherThan(const Vertex &other) const
{
    return m_row > other.m_row;
}
// ___________________________________________________
bool Vertex::isToTheRightOf(const Vertex &other) const
{
    return m_col > other.m_col;
}
// _________________________
bool Vertex::isValid() const
{
    return m_col >= 0 && m_col <= MAX_COL && m_row >= 0 && m_row <= MAX_ROW;
}
// _________________________________________
bool Vertex::isQuad(const Vertex v2) const
{
    return this->isHigherThan(v2) &&
           this->isToTheRightOf(v2) &&
           this->isValid() && v2.isValid();
}
// ____________________________________________________________
bool Vertex::isTriangle(const Vertex v1, const Vertex v2) const
{
    return this->isValid() && v1.isValid() &&
           v2.isValid();
}
// ____________________________________________________
std::istream &operator>>(std::istream &istr, Vertex &v)
{
    return istr >> v.m_col >> v.m_row;
}
// __________________________________________________________
std::ostream &operator<<(std::ostream &ostr, const Vertex &v)
{
    return ostr << "(" << v.m_col << ", " << v.m_row << ")";
}
