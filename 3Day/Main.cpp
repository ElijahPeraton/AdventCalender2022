#include <iostream>
#include <fstream>
#include "Priority.h"
#include "Processing.h"

#define INPUT_FILE_PATH "./input/input.txt"

int main() {
  std::fstream f;
  std::string line;
  f.open(INPUT_FILE_PATH);

  if( !f.is_open() ) {
    std::cout << "Failure to read file " << INPUT_FILE_PATH << std::endl;
    return -1;
  }

  int total;
  while(std::getline(f, line)) {
    char repeatedChar = Processing::findRepeat(line);
    total += Priority::calculateFromChar(repeatedChar);
  }

  std::cout << "total priority: " << total << std::endl;

  return 0;
}
