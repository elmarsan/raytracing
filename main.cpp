#include <iostream>

#include "color.h"
#include "ray.h"
#include "vector"

// blendedValue=(1−t)⋅startValue+t⋅endValue
Color rayColor(const Ray &r) {
  Vec3 unitDirection = unitVector(r.direction());
  auto t = 0.5 * (unitDirection.y() + 1.0);
  return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

bool hitSphere(const Point3 center, double radius, const Ray&r) {
  auto r2 = radius * radius;

  return true;
}

int main() {
  // Image
  const auto aspectRatio = 16.0 / 9.0;
  const int imageWidth = 400;
  const int imageHeight = static_cast<int>(imageWidth / aspectRatio);

  // Camera
  auto viewportHeight = 2.0;
  auto viewportWidth = aspectRatio * viewportHeight;
  auto focalLength = 1.0;

  auto origin = Point3(0, 0, 0);
  auto horizontal = Vec3(viewportWidth, 0, 0);
  auto vertical = Vec3(0, viewportHeight, 0);
  auto lowerLeftCorner =
      origin - horizontal / 2 - vertical / 2 - Vec3(0, 0, focalLength);

  // Render
  std::cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";

  for (int j = imageHeight - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < imageWidth; ++i) {
      auto u = double(i) / (imageWidth - 1);
      auto v = double(j) / (imageHeight - 1);
      Ray r(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
      Color pixel_color = rayColor(r);
      writeColor(std::cout, pixel_color);
    }
  }

  std::cerr << "\nDone.\n";

  // PPM Image
  // const int imageWidth = 256;
  // const int imageHeight = 256;

  // // Render
  // std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

  // for (int j = imageHeight - 1; j >= 0; --j) {
  //   for (int i = 0; i < imageWidth; ++i) {
  //     auto r = double(i) / (imageWidth - 1);
  //     auto g = double(j) / (imageWidth - 1);
  //     auto b = 0.25;

  //     Color pixelColor(r,g,b);
  //     writeColor(std::cout, pixelColor);
  //   }
  // }
}
