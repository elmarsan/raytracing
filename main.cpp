#include <iostream>

#include "color.h"

int main() {
  const int imageWidth = 256;
  const int imageHeight = 256;

  // Render
  std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

  for (int j = imageHeight - 1; j >= 0; --j) {
    for (int i = 0; i < imageWidth; ++i) {
      auto r = double(i) / (imageWidth - 1);
      auto g = double(j) / (imageWidth - 1);
      auto b = 0.25;

      Color pixelColor(r,g,b);
      writeColor(std::cout, pixelColor);
    }
  }
}
