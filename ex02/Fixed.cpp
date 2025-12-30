#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called\n";
}

Fixed::Fixed(int const value)
{
    _value = value << _fractionalBits;
    std::cout << "Int constructor called\n";
}

Fixed::Fixed(float const value)
{
    _value = roundf(value * 256);
    std::cout << "Float constructor called\n";
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

int Fixed::toInt() const {
    return _value >> _fractionalBits;
}

float Fixed::toFloat() const {
    return static_cast<float>(_value) / 256;
}

bool Fixed::operator>(const Fixed &fixed) const
{
    return _value > fixed._value;
}

bool Fixed::operator<(const Fixed &fixed) const
{
    return _value < fixed._value;
}

bool Fixed::operator>=(const Fixed &fixed) const
{
    return _value >= fixed._value;
}
bool Fixed::operator<=(const Fixed &fixed) const
{
    return _value <= fixed._value;
}
bool Fixed::operator==(const Fixed &fixed) const
{
    return _value == fixed._value;
}
bool Fixed::operator!=(const Fixed &fixed) const
{
    return _value != fixed._value;
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    Fixed result;
    result.setRawBits(_value + fixed._value);
    return result;
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    Fixed result;
    result.setRawBits(_value - fixed._value);
    return result;
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    Fixed result;
    result.setRawBits((_value * fixed._value) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    Fixed result;
    result.setRawBits((_value << _fractionalBits) / fixed._value);
    return result;
}
Fixed& Fixed::operator++()
{
    _value++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    _value++;
    return temp;
}

Fixed& Fixed::operator--()
{
    _value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    _value--;
    return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a < b)
        return a;
    return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a > b)
        return a;
    return b;
}


std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
