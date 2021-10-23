#include "Utilities.h"
#include <cmath>

bool doubleEqual(double a, double b)
{
    return std::abs(a - b) < 0.5;
}

double distance(const Vertex& v1, const Vertex& v2)
{
    return std::hypot(v1.getCol() - v2.getCol(), v1.getRow() - v2.getRow());
}

bool sameCol(const Vertex& v1, const Vertex& v2)
{
    return std::round(v1.getCol()) == std::round(v2.getCol());
}

bool sameRow(const Vertex& v1, const Vertex& v2)
{
    return std::round(v1.getRow()) == std::round(v2.getRow());
}
