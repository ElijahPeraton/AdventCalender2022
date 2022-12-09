#include <stdio.h>
#include <string>
#include <iostream>

namespace Processing {

  // Command derives from one string of input file
  // format: move ### from ### to ###
  // Assert: no guarantee about number of digits
  struct Command {
    int multiplicity;
    int from;
    int to;
    Command(std::string input) {
      // Find integers based on spaces
      int space1, space2, space3, space4, space5;

      // Squeeze number 1
      space1 = input.find(" ", 0)+1;
      space2 = input.find(" ", space1);

      // Squeeze number 2
      space3 = input.find(" ", space2+1)+1;
      space4 = input.find(" ", space3);

      // Squeeze last number (no need to find end )
      space5 = input.find(" ", space4+1)+1;

      multiplicity  = std::stoi(input.substr(space1, space2-space1) );
      from          = std::stoi(input.substr(space3, space4-space3) );
      to            = std::stoi(input.substr(space5) );
    }
  }; // End Command
}