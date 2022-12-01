#include <iostream>
#include <fstream>
#include <string>

#define INPUT_PATH "./input.txt"

#define END_LINE 0 // MUST be 0000
#define END_FILE -1


/*
* Helper Function
*/
int getCalorie(std::ifstream& f) {
  // Case: end of file
  if(!f.good())
    return END_FILE;

  try {
    // Case: calories to count
    std::string in;
    std::getline(f, in);
    return stoi(in);
  } catch (...) {
    // case: no calories; failure to integer-convert '\n'
    return END_LINE;
  }
}


int main() {
  // Access File
  std::ifstream f(INPUT_PATH);
  std::string in;

  if(!f.is_open())
    return -1;

  // Parse
  int max=0;
  for(int c=0, sum=0; c!=END_FILE; c=getCalorie(f)) {
      if(c) sum += c;
      else {
        max = (sum>max) ? sum : max;
        sum = 0;
      }
  }

  printf("max calories: %d\n", max);

  return 0;
}
