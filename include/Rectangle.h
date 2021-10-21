#pragma once

#include <iosfwd>
#include "Vertex.h"

class Rectangle
{
public:
    Rectangle(const Vertex &bottomLeft, const Vertex &topRight); // 1
    Rectangle(const Vertex vertices[2]);
    Rectangle(double x0, double y0, double x1, double y1);
    Rectangle(const Vertex& start, double width, double height);
    ~Rectangle();

    Vertex getBottomLeft() const; // 1
    Vertex getTopRight() const;   // 1
    double getWidth() const;
    double getHeight() const;

private:
    double m_bottom_left_x;
    double m_bottom_left_y;
    double m_top_right_x;
    double m_top_right_y;
};
