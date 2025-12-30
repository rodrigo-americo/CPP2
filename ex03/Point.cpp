#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point::~Point() {}

Point &Point::operator=(const Point &point) {
    (void)point;
    return *this;
}

Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}
