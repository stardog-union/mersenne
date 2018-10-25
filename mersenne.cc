#include <iostream>

#include "lucas.h"

int main(int argc, char* argv[]) {
  for (long i = 0; i < 50; ++i) {
    std::cout << i << " " << mersenne(i) << std::endl;
  }
  return 0;
}
