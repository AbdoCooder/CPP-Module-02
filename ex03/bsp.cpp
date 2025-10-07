// Copyright (c) 2025 Abdelkader Benajiba

#include "Fixed.hpp"
#include "Point.hpp"

// the surface of a triangle given by 3 points
// 1/2 | x0(y1-y2) + x1 (y2-y0) + x2(y0-y1) |

static float ft_fabs(float value) { return (value < 0) ? -value : value; }

static Fixed surface(Point const &a, Point const &b, Point const &c) {
  float x0 = a.getX().toFloat();
  float y0 = a.getY().toFloat();

  float x1 = b.getX().toFloat();
  float y1 = b.getY().toFloat();

  float x2 = c.getX().toFloat();
  float y2 = c.getY().toFloat();
  ;

  return (0.5f * ft_fabs(x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1)));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
  Fixed total_surface = surface(a, b, c);
  Fixed a1 = surface(a, b, point);
  Fixed a2 = surface(a, point, c);
  Fixed a3 = surface(point, b, c);

  if (total_surface != a1 + a2 + a3 || a1 == 0 || a2 == 0 || a3 == 0)
    return false;
  return true;
}
