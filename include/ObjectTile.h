#include <vector>
#include <string>

#include "BoardLocation.h"


class ObjectTile
{
public:
    void showShape()const;

private:
    std::string texture;
    std::string shape;
    std::vector <BoradLocation>locations;

};