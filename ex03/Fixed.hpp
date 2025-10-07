// Copyright 2025 Abdelkader Benajiba

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
 public:
  // ctors
  Fixed();
  Fixed(const int rawBits);
  Fixed(const float rawBits);
  // copy ctor
  Fixed(const Fixed &other);
  // copy assignment operator
  Fixed &operator=(const Fixed &other);
  // increment / decrement operators
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);
  // comparison operators
  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;
  // arithmetic operators
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;
  // min / max
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(const Fixed &a, const Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(const Fixed &a, const Fixed &b);
  // dtor
  ~Fixed();
  // getters
  int getRawBits(void) const;
  // setters
  void setRawBits(int const raw);
  // converters
  float toFloat(void) const;
  int toInt(void) const;

 private:
  int rawBits;
  static const int fract_bits;
};

// Overload of the insertion operator
std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif  // FIXED_HPP
