// Jemin Song
// jeminsong0119@csu.fullerton.edu
// @jeminsong
// Partners: @Card1n

#include <Magick++.h>

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "animated_gradient_functions.h"

// The width of the image is the number of columns.
const int kImageWidth{512};
// The height of the image is the number of rows.
const int kImageHeight{512};
// The number of images in our flipbook animation.
const int kNumberOfImages = 10;

int main(int argc, char* argv[]) {
  // Initialize the GraphicsMagick library. It must be the first thing
  // that happens in the main function.
  // Do not change or remove the line below.
  Magick::InitializeMagick(*argv);
  std::vector<std::string> args(argv, argv + argc);
  std::cout << args.size() << "\n";
  for (const std::string& args : args) {
    std::cout << args << "\n";
  }
  if (args.size() < 2) {
    std::cout << "Please provide a path to a file";
    return 1;
  }
  std::string output_file_name = args.at(1);
  std::string image_format = "gif";
  if (HasMatchingFileExtension(output_file_name, image_format) == false) {
    std::cout << output_file_name
              << " is missing the required file extension .gif.\n";
    return 1;
  }

  std::vector<double> sine_lookup_table = BuildSineLookupTable(kImageWidth);
  Magick::ColorRGB white(1, 1, 1);
  std::vector<Magick::Image> image_vector;
  double blue_step = M_PI / static_cast<double>(kNumberOfImages);
  int row_col_step = kImageWidth / kNumberOfImages;

  for (int current_image = 0; current_image < kNumberOfImages;
       current_image++) {
    Magick::Image image(Magick::Geometry(kImageWidth, kImageHeight), white);
    std::cout << "Image " << current_image + 1 << "...";

    double blue = sin(blue_step * current_image);
    for (int column = 0; column < image.columns(); ++column) {
      for (int row = 0; row < image.rows(); row++) {
        int current_step = (current_image * row_col_step);
        double red = sine_lookup_table.at((row + current_step) % kImageWidth);
        double green =
            sine_lookup_table.at((column + current_step) % kImageHeight);
        Magick::ColorRGB color(red, green, blue);
        image.pixelColor(column, row, color);
      }
    }
    image_vector.push_back(image);
    std::cout << " Image " << current_image + 1 << "completed.\n";
  }
  Magick::writeImages(image_vector.begin(), image_vector.end(),
                      output_file_name);
  return 0;
}