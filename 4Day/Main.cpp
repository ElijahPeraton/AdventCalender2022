#include <iostream>
#include <fstream>
#include "Processing.h"

#define PATH_TO_FILE "./input/input.txt"

int main() {
  std::ifstream f;
  std::string line;
  f.open(PATH_TO_FILE);

  if(!f.is_open()) {
    std::cout << "Failure to open file" << std::endl;
    return -1;
  }

  int arr[4];
  int elf1Start, elf2Start, elf1End, elf2End;
  int starts, ends;
  int total = 0;
  while(f.good()) {
    std::getline(f, line);
    std::cout << line << std::endl;

    Processing::lineToIntArray(line, arr);
    elf1Start = arr[0];
    elf1End   = arr[1];
    elf2Start = arr[2];
    elf2End   = arr[3];

    /* winning scenarios
      For expressions elf1 - elf2

      Starts    Ends
       1(-)2   2(+)1
    |--x---x---x---x---|

       2(+)1   1(-)2
    |--x---x---x---x---|

      Note: 1 - 2 == 0 is always acceptable (whether positive or negative)
    */
    starts = elf1Start - elf2Start;
    ends = elf1End - elf2End;

    bool oppositeSigns = (starts<=0 && ends>=0) || (starts>=0 && ends<=0);
    if(oppositeSigns) {
      std::cout << "FOUND" << std::endl;
      total++;
    }
  }

  std::cout << "Total: " << total << std::endl;
  return 0;
}