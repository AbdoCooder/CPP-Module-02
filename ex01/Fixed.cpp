// Copyright 2025 Abdelkader Benajiba

#include "Fixed.hpp"

#include <iostream>

// Static member definitions
const int Fixed::fract_bits = 8;

Fixed::Fixed() : rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int rawBits) : rawBits(rawBits >> fract_bits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float rawBits) : rawBits(static_cast<int>(rawBits * (1 << fract_bits))) {
  std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->rawBits = other.rawBits;
  }
  return *this;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->rawBits;
}

void Fixed::setRawBits(int const raw) { this->rawBits = raw; }

float Fixed::toFloat( void ) const {
  return static_cast<float>(this->rawBits) / (1 << fract_bits);
}

int Fixed::toInt( void ) const {
  return this->rawBits >> fract_bits;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
  out << fixed.toFloat();
  return out;
}
