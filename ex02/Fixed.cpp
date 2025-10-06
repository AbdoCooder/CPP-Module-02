// Copyright 2025 Abdelkader Benajiba

#include "Fixed.hpp"

#include <iostream>
#include <cmath>

// Static member definitions
const int Fixed::fract_bits = 8;

Fixed::Fixed() : rawBits(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int rawBits) : rawBits(rawBits << fract_bits) {
  std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float rawBits) : rawBits(static_cast<int>(roundf(rawBits * (1 << fract_bits)))) {
  std::cout << static_cast<int>(roundf(rawBits * (1 << fract_bits))) << std::endl;
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

// Increment / Decrement operators ==============================================================
Fixed &Fixed::operator++() {
  this->rawBits++;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed temp = *this;
  this->rawBits++;
  return temp;
}

Fixed &Fixed::operator--() {
  this->rawBits--;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed temp = *this;
  this->rawBits--;
  return temp;
}

// Comparison operators ==============================================================
bool Fixed::operator>(const Fixed &other) const {
  return this->rawBits > other.rawBits;
}

bool Fixed::operator<(const Fixed &other) const {
  return this->rawBits < other.rawBits;
}

bool Fixed::operator>=(const Fixed &other) const {
  return this->rawBits >= other.rawBits;
}

bool Fixed::operator<=(const Fixed &other) const {
  return this->rawBits <= other.rawBits;
}

bool Fixed::operator==(const Fixed &other) const {
  return this->rawBits == other.rawBits;
}

bool Fixed::operator!=(const Fixed &other) const {
  return this->rawBits != other.rawBits;
}

// Arithmetic operators ==============================================================
Fixed Fixed::operator+(const Fixed &other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
  if (other.rawBits == 0) {
    std::cerr << "Division by zero error" << std::endl;
    return Fixed();
  }
  return Fixed(this->toFloat() / other.toFloat());
}

// Min / Max ==============================================================
Fixed &Fixed::min(Fixed &a, Fixed &b) {
  return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  return (a > b) ? a : b;
}
