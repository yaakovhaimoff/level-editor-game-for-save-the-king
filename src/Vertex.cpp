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
           v2.isValid() &&
           doubleEqual(this->m_row, v1.m_row) &&
           doubleEqual(this->m_row, v2.m_row);
}
// ____________________________________________________
void Vertex::drawQuad(Board &board, const Vertex v1) const
{
    board.drawLine(Vertex(this->m_col, this->m_row), Vertex(v1.m_col, this->m_row));
    board.drawLine(Vertex(v1.m_col, this->m_row), v1);
    board.drawLine(v1, Vertex(this->m_col, v1.m_row));
    board.drawLine(Vertex(v1.m_col, this->m_row),
                   Vertex(this->m_col, this->m_row));
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
