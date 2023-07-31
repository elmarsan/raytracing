#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <ostream>

class Vec3 {
public:
  Vec3();
  Vec3(double e0, double e1, double e2);

  double x() const;
  double y() const;
  double z() const;

  Vec3 operator-() const;
  double operator[](int i) const;
  double &operator[](int i);
  Vec3 &operator+=(const Vec3 &v);
  Vec3 &operator*=(const double scalar);
  Vec3 operator*(const double scalar);

  inline double dot(const Vec3 &u, const Vec3 &v);
  double length() const;

public:
  double e[3];
};

using Point3 = Vec3;

#endif
