// Copyright 2025 Abdelkader Benajiba

#ifndef EX00_FIXED_HPP_
#define EX00_FIXED_HPP_

#include <iostream>

class Fixed {
 public:
  Fixed();
  Fixed(const Fixed &other);
  Fixed &operator=(const Fixed &other);
  ~Fixed();

 private:
  int               value;
  static const int  fract_bits;
};

#endif  // EX00_FIXED_HPP_
