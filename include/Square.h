#pragma once
#include "Vertex.h"

class Square
{
public:
    Square(const Vertex& bottomLeft, const Vertex& topRight);
    Square(const Vertex& start, double length);
    ~Square();
    Vertex getBottomLeft(const double leftBottomVertex);
    Vertex getTopRight(const double rightTopVertex);
    Vertex getTopLength(const double topLength);

private:
    /* data */
};

