#include <iostream>
#include <fstream>
#include "SignalProcessing.hpp"

#define INPUT_FILE_PATH "input/ex5.txt"

int main() {
  // Open file
  std::ifstream f;
  f.open(INPUT_FILE_PATH);

  if(!f.is_open()) {
    std::cout << "Could not open " << INPUT_FILE_PATH << std::endl;
    return -1;
  }

  // Process through file one char at a time
  SignalProcessing::CharMemory memory;
  SignalProcessing::UniqueSequenceIdentifier identifier (memory);


  char ch;
  int iter = 1;
  while(f >> ch) {
    // print character
    // Register it
    // See if unique sequence found

    std::cout << ch << std::endl;
    identifier.registerChar(ch);
    bool mostRecentAreUnique = identifier.allUnique();

    if(mostRecentAreUnique) {
      std::cout << "Unique! at " << std::to_string(iter) << std::endl;
      break;
    }

    iter++;
  }

  return 0;
}
