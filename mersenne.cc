#include <iostream>

#include "lucas.h"

constexpr long(*mersenne)(long) = &lucas_first<3, 2>;

int main(int argc, char* argv[]) {
  for (long i = 0; i < 50; ++i) {
    std::cout << i << " " << mersenne(i) << std::endl;
  }
  return 0;
}
