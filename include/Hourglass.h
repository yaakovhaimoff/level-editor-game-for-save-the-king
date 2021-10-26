#pragma once

#include "Board.h"
#include "Vertex.h"
#include "Triangle.h"
#include "Utilities.h"
#include <cmath>

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
    bool isHourglass(const Triangle &upper,
                     const Triangle &lower) const;
    bool isUpperAndLower(const Triangle &upper,
                         const Triangle &lower) const;
    bool isVertexShared(const Triangle &upper,
                         const Triangle &lower) const;
    bool isLengthSame(const Triangle &upper,
                         const Triangle &lower) const;
};
