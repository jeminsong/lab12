// Jemin Song
// jeminsong0119@csu.fullerton.edu
// @jeminsong
// Partners: @Card1n

#include "animated_gradient_functions.h"

#include <cmath>
#include <iostream>

bool HasMatchingFileExtension(const std::string& file_name,
                              const std::string& extension) {
  if (file_name.length() >= extension.length()) {
    return (file_name.compare(file_name.length() - extension.length(),
                              extension.length(), extension) == 0);
  }
  return false;
}

std::vector<double> BuildSineLookupTable(int image_width) {
  std::vector<double> lookup_table;
  double angle_step = M_PI / image_width;
  for (int i = 0; i < image_width; ++i) {
    double angle = angle_step * i;
    lookup_table.push_back(std::sin(angle));
  }
  return lookup_table;
}