#include "Cargo.hpp"
#include <stdio.h>


Cargo::CargoShip::CargoShip(int nStacks) : nLines(nStacks){
  // Array of LL
  lines = new CrateStack[nLines];
}

Cargo::CargoShip::~CargoShip() {
  // Do nothing? deleting lines crates segfault
}

void Cargo::CargoShip::load(int stackNumber, char crate) {
  lines[stackNumber-1].push(crate);
}

char Cargo::CargoShip::unload(int stackNumber) {
  char c = lines[stackNumber-1].top();
  lines[stackNumber-1].pop();
  return c;
}

void Cargo::CargoShip::move(int from, int to) {
  char c = unload(from);
  load(to, c);
}

// Move multiple crates while preserving their original order (NOT inverting order)
void Cargo::CargoShip::moveMultiple(int n, int from, int to) {
  // Recursive
  bool allUnloaded = n==0;
  if(allUnloaded) return;

  char c = unload(from);
  // std::cout << "Unloading " << c << std::endl;
  moveMultiple(--n, from, to);
  // std::cout << "Loading " << c << std::endl;
  load(to, c);
}


// Helper function
// Taking advantage of pass by value
// Print recursively bottom->top
void print_Stack(std::stack<Cargo::Crate> stack) {
  if(stack.empty()) return;

  char c = stack.top();
  stack.pop();
  print_Stack(stack);
  // print backwards
  printf("[%c]", c);
}

void Cargo::CargoShip::show() {
  printf("lines: %p(%p)\n", &lines, lines);

  for(int i=0; i<nLines; i++) {
    printf("%d: %p ", i+1, &lines[i]);
    print_Stack(lines[i]);
    printf("\n");
  }
}
