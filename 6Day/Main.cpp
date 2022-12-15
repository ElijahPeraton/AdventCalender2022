#include <iostream>
#include <fstream>
#include "SignalProcessing.hpp"

#define INPUT_FILE_PATH "input/input.txt"

int main() {
  // Open file
  std::ifstream f;
  f.open(INPUT_FILE_PATH);

  if(!f.is_open()) {
    std::cout << "Could not open " << INPUT_FILE_PATH << std::endl;
    return -1;
  }

  // Signal Processing Modules
  int messageLength = 14;
  SignalProcessing::CharMemory memory(messageLength);
  SignalProcessing::UniqueSequenceIdentifier identifier (memory);


  // Process through file one char at a time
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
