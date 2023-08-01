#include "vec3.h"
#include <cmath>
#include <ostream>

Vec3::Vec3() : e{0, 0, 0} {}
Vec3::Vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

double Vec3::x() const { return e[0]; }
double Vec3::y() const { return e[1]; }
double Vec3::z() const { return e[2]; }

Vec3 Vec3::operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
double Vec3::operator[](int i) const { return e[i]; }
double &Vec3::operator[](int i) { return e[i]; }

Vec3& Vec3::operator+=(const Vec3 &v) {
  e[0] += v.e[0];
  e[1] += v.e[1];
  e[2] += v.e[2];
  return *this;
}

Vec3& Vec3::operator*=(const double scalar) {
  e[0] *= scalar;
  e[1] *= scalar;
  e[2] *= scalar;
  return *this;
}

double Vec3::length() const {
    return std::sqrt(std::pow(e[0], 2) + std::pow(e[1], 2) + std::pow(e[2], 2));
}
