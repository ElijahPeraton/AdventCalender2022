#include <iostream>
#include <fstream>
#include "Priority.h"
#include "Processing.h"

#define INPUT_FILE_PATH "./input/input.txt"

int main() {
  std::fstream f;
  std::string l1, l2, l3;
  f.open(INPUT_FILE_PATH);

  if( !f.is_open() ) {
    std::cout << "Failure to read file " << INPUT_FILE_PATH << std::endl;
    return -1;
  }

  int total = 0;
  while(f.good()) {
    std::getline(f, l1); // 3 reads
    std::getline(f, l2);
    std::getline(f, l3);
    std::cout << l1 << std::endl << l2 << std::endl << l3 << std::endl;
    char repeatedChar = Processing::findGroupRepeat(l1, l2, l3);
    total += Priority::calculateFromChar(repeatedChar);
  }

  std::cout << "total priority: " << total << std::endl;

  return 0;
}
