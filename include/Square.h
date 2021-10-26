#pragma once
#include "Board.h"
#include "Vertex.h"
#include "Rectangle.h"

class Square
{
public:
    Square(const Vertex& bottomLeft, const Vertex& topRight);
    Square(const Vertex& start, double length);

    ~Square();
    Vertex getBottomLeft()const;
    Vertex getTopRight()const;
    double getLength()const;

    void draw(Board& board) const;
    Rectangle getBoundingRectangle()const;
    double getArea()const;
    Vertex getCenter()const;
    bool scale(double factor);

private:
    Vertex m_bottomLeft;
    Vertex m_topRight;
};

