#ifndef RAY_H
#define RAY_H

#include "vec3.h"

/*  P(t) = A + tb
 *  P = 3d position
 *  A = Origin of the ray
 *  b = Direction of the ray
 *  T = double parameter
 */
class Ray {
public:
  Ray(); 
  Ray(const Point3 &origin, const Vec3 &direction);
 
  Point3 origin() const;
  Vec3 direction() const;
  Point3 at(const double t) const;

public:
  Point3 orig;
  Vec3 dir;
};

#endif
