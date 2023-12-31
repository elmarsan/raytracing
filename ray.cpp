#include "ray.h"
#include "vec3.h"

Ray::Ray() {}

Ray::Ray(const Point3 &origin, const Vec3 &direction)
    : orig(origin), dir(direction) {}

Point3 Ray::origin() const { return orig; }
Vec3 Ray::direction() const { return dir; }
Point3 Ray::at(const double t) const {
    return orig + t * dir;
}
