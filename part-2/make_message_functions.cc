// Jemin Song
// jeminsong0119@csu.fullerton.edu
// @jeminsong
// Partners: @Card1n

#include "make_message_functions.h"

#include <iomanip>

bool HasMatchingFileExtension(const std::string& file_name,
                              const std::string& extension) {
  if (file_name.length() >= extension.length()) {
    return (file_name.compare(file_name.length() - extension.length(),
                              extension.length(), extension) == 0);
  }
  return false;
}

// Secret global variable to make the randome number generator
// predictable
std::seed_seq rng_seed{1, 2, 3, 4, 5};

// Secret global variable that is used by RandomDouble_01()
RandomNumberGenerator rng_01{0, 1, rng_seed};

// Secret global variable that is used by RandomDouble_11()
RandomNumberGenerator rng_11{-1, 1, rng_seed};

// Secret global variable that is used by CoinFlip()
RandomNumberGenerator rng_coin_flip{-1, 1, rng_seed};

// Returns a random double between o and 1
double RandomDouble01() { return rng_01.Next(); }

// Returns a random double between -1 and 1
double RandomDouble11() { return rng_11.Next(); }

/// Return a True or False depending on a random value.
/// Generates a random number and then decides to return True or False
bool CoinFlip() {
  return rng_coin_flip.Next() > 0.0;

  // number is greater than 0.0 and false otherwise.
}
