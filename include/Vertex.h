#pragma once

#include <iosfwd>

class board;

struct Vertex
{
    double m_col = 0; // x
    double m_row = 0; // y
    
    // Constructors
    Vertex() = default;
    Vertex(double col, double row) : m_col(col), m_row(row) {}

    // Services
    bool isHigherThan(const Vertex &other) const;
    bool isToTheRightOf(const Vertex &other) const;
    bool isValid() const;
    bool isQuad(const Vertex v2) const;
    bool isTriangle(const Vertex v2, const Vertex v3) const;

    void drawQuad(Board &board, const Vertex v1) const;
};

std::istream &operator>>(std::istream &istr, Vertex &v);
std::ostream &operator<<(std::ostream &ostr, const Vertex &v);
