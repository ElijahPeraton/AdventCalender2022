#ifndef CARGO_HPP
#define CARGO_HPP

#include <string>
#include <iostream>
#include <stack>

namespace Cargo {
  typedef char Crate;
  typedef std::stack<Crate> CrateStack;

  // ASSERT: number of stacks never changes for cargo ship
  class CargoShip {
  public:
    CargoShip(int nStacks);
    ~CargoShip();
    void load(int stackNumber, char crate);
    char unload(int stackNumber);
    void move(int from, int to);
    void moveMultiple(int n, int from, int to);
    void show();
  private:
    // Array of Stacks
    CrateStack *lines;
    int nLines;
  }; // End CargoShip


} // End Cargo

#endif
