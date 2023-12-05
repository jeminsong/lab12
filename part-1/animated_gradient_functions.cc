// Jemin Song
// jeminsong0119@csu.fullerton.edu
// @jeminsong
// Partners: @Card1n

#include "animated_gradient_functions.h"

#include <cmath>
#include <iostream>

bool HasMatchingFileExtension(const std::string& file_name,
                              const std::string& extension) {
  if (file_name.length() >= extension.length() &&
      (file_name.compare((file_name.length() - extension.length()),
                         extension.length(), extension) == 0)) {
    return true;
  }
  return false;
}

std::vector<double> BuildSineLookupTable(int image_width) {
  std::vector<double> lookup_table;
  double radian_step = M_PI / image_width;
  for (int column = 0; column < image_width; column++) {
    double value = sin(radian_step * column);
    lookup_table.push_back(value);
  }
  return lookup_table;
}