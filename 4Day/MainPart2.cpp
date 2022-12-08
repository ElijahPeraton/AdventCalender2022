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
  int total = 0;
  while(f.good()) {
    std::getline(f, line);
    std::cout << line << std::endl;

    Processing::lineToIntArray(line, arr);
    elf1Start = arr[0];
    elf1End   = arr[1];
    elf2Start = arr[2];
    elf2End   = arr[3];

    /* Winning Scenarios (no overlap)

       1   1   2   2
    |--x---x---x---x---|

       2   2   1   1
    |--x---x---x---x---|

      Determine whether elf2's end falls below elf1, or elf2's start falls after
      Must be strictly greater / less than
      Take advantage of section assignments being strictly sequential (only test start or end)
      There's probably an elegant mathematical way to do this but this method is quick, simple, and straight-forward
    */
    bool higher = (elf2Start>elf1Start && elf2Start>elf1End);
    bool lower = (elf2End<elf1Start && elf2End<elf1End);

    bool noOverlap = lower || higher;
    if(!noOverlap) {
      std::cout << "FOUND" << std::endl;
      total++;
    }
  }

  std::cout << "Total: " << total << std::endl;
  return 0;
}