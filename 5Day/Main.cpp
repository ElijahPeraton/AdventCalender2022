#include "Cargo.hpp"
#include "Processing.hpp"
#include <iostream>
#include <fstream>

#define INPUT_FILE_PATH "./input/input.txt"

#define BUILD_SIMPLE Cargo::CargoShip ship(3); \
  quickBuild(ship, 1, "ZN"); \
  quickBuild(ship, 2, "MCD"); \
  quickBuild(ship, 3, "P");

#define BUILD_SHIP Cargo::CargoShip ship(9); \
  quickBuild(ship, 1, "GFVHPS"); \
  quickBuild(ship, 2, "GJFBVDZM"); \
  quickBuild(ship, 3, "GMLJN"); \
  quickBuild(ship, 4, "NGZVDWP"); \
  quickBuild(ship, 5, "VRCB"); \
  quickBuild(ship, 6, "VRSMPWLZ"); \
  quickBuild(ship, 7, "THP"); \
  quickBuild(ship, 8, "QRSNCHZV"); \
  quickBuild(ship, 9, "FLGPVQJ");


void quickBuild(Cargo::CargoShip target, int stackNumber, std::string crates) {
  for(int i=0; i<crates.length();i++) {
    target.load(stackNumber, crates[i]);
  }
}


int main() {
  std::ifstream f;
  f.open(INPUT_FILE_PATH);

  if(!f.is_open()) {
    std::cout << "Failed to open file" << std::endl;
    return -1;
  }
  // Building cargo based on picture


  BUILD_SHIP
  ship.show();

  std::string s;
  while(f.good()) {
    std::getline(f, s);
    Processing::Command cmd(s);

    while(cmd.multiplicity--) {
      ship.move(cmd.from, cmd.to);
    }
  }

  ship.show();

}