#include "Fixed.hpp"
#include "Point.hpp"

static Fixed triangleArea(Point const p1, Point const p2, Point const p3)
{
    Fixed area;
    area = p1.getX() * (p2.getY() - p3.getY()) + 
           p2.getX() * (p3.getY() - p1.getY()) + 
           p3.getX() * (p1.getY() - p2.getY());
    if (area < Fixed(0))
        area = area * Fixed(-1);
    area = area / Fixed(2);
    return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed diff;
    Fixed sum;
    Fixed areaABC = triangleArea(a, b, c);
    Fixed areaPBC = triangleArea(point, b, c);
    Fixed areaPCA = triangleArea(point, c, a);
    Fixed areaPAB = triangleArea(point, a, b);
    if (areaPBC == Fixed(0) || areaPCA == Fixed(0) || areaPAB == Fixed(0))
        return false;
    sum = areaPBC + areaPCA + areaPAB;
    if (areaABC > sum)
        diff = areaABC - sum;
    else
        diff = sum - areaABC;
    return diff <= Fixed(0.01f); 
}