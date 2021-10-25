#pragma once

#include <iosfwd>
#include "Vertex.h"
#include "Board.h"
#include "Triangle.h"

class Hourglass
{
public:
    Hourglass(const Triangle &upper,
              const Triangle &lower);
    Hourglass(const Triangle &lower);

    double getLength() const;
    double getHeight() const;

    void draw(Board &board) const;
    Rectangle getBoundingRectangle() const;
    double getArea() const;
    double getPerimeter() const;
    Vertex getCenter() const;
    bool scale(double factor);

private:
    Triangle m_topTriangle;
    Triangle m_bottomTriangle;
};
