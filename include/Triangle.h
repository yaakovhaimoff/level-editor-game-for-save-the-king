#pragma once

#include <iosfwd>
#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"

class Triangle
{
public:
    Triangle(const Vertex vertcies[3]);
    Triangle(const Vertex &v0,
             const Vertex &v1, double height);
    Vertex getVertex(int index) const;
    double getLength()const;
    double getHeight()const;

    void draw(Board& board) const;
    Rectangle getBoundingRectangle()const;
    double getArea()const;
    Vertex getCenter()const;
    bool scale(double factor);

private:
    Vertex m_triangleVertex[3];
};
