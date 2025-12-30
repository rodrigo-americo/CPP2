#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed &fixed) : _value(fixed._value) {
    std::cout << "Copy constructor called\n";
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
    std::cout << "Copy assignment operator called\n";
    if (this != &fixed)
        _value = fixed._value;
    return *this;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return _value;
}