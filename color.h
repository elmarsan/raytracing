#ifndef COLOR_H
#define COLOR_H

#include "vec3.h"
#include <ostream>

using Color = Vec3;

void writeColor(std::ostream &out, Color color) {
  int ir = static_cast<int>(255.999 * color.x());
  int ig = static_cast<int>(255.999 * color.y());
  int ib = static_cast<int>(255.999 * color.z());

  out << ir << ' ' << ig << ' ' << ib << '\n';
}

#endif
