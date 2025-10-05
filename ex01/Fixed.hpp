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
  // dtor
  ~Fixed();
  // getters
  int getRawBits(void) const;
  // setters
  void setRawBits(int const raw);
  // converters
  float toFloat( void ) const;
  int toInt( void ) const;
  
  private:
  int rawBits;
  static const int fract_bits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif  // FIXED_HPP
