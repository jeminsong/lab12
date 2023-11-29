// TODO: Add your header

#include "animated_gradient_functions.h"

#include <cmath>
#include <iostream>

bool HasMatchingFileExtension(const std::string& file_name,
                              const std::string& extension) {
  // TODO: Implement this function.
  // Check if the length of the file_name is greater than
  // or equal to the length of extension and compare if file_name ends
  // with the extension using the compare member function, see
  // https://en.cppreference.com/w/cpp/string/basic_string/compare
  // Hint: Use file_name's compare member function:
  //      file_name.compare()
  // It will take three parameters.
  // The first parameter is where you want to start comparing.
  // Mathematically, this is the length of file_name minus the length
  // of extension.
  // The second parameter is how many letters you want to check
  // which is the length of extension.
  // The third parameter is what you want to compare file_name to,
  // which is extension.
  // Remember that file_name.compare() returns 0 if the comparison
  // is true. This means you will want to use the 'equal to' operator
  // '==' to check to see if file_name.compare() returned 0.
  // ex. file_name.compare() == 0
  return false;
}

std::vector<double> BuildSineLookupTable(int image_width) {
  std::vector<double> lookup_table;
  // TODO: build the lookup table and return it to the caller
  // divide 180 degrees (M_PI) over number of columns or rows
  // we work in radians because the math library works in radians.
  return lookup_table;
}
