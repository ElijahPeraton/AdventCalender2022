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


/*
* Helper Structure
*/
template <typename T>
class ThreeBuffer {
  T buff[3];
  T lowestIdx;
public:
  ThreeBuffer() : buff{0,0,0} {}

  // Possibly kick out lowest value
  void consider(T val) {
    lowestIdx = ( buff[0]<buff[1] )         ? 0 : 1;
    lowestIdx = ( buff[lowestIdx]<buff[2] ) ? lowestIdx : 2;
    if( val>buff[lowestIdx] ) buff[lowestIdx]=val;
  }

  void showBuff() {
    printf("[%d %d %d]", buff[0], buff[1], buff[2]);
  }

  T& operator[](int idx) {
    return buff[idx]; // Responbility placed onto user
  }
};


int main() {
  // Access File
  std::ifstream f(INPUT_PATH);
  std::string in;
  ThreeBuffer<int> buff;

  if(!f.is_open())
    return -1;


  // Parse
  for(int c=0, sum=0, max=0; c!=END_FILE; c=getCalorie(f)) {
      if(c) sum += c;
      else {
        buff.consider(sum);
        sum = 0;
      }
  }

  printf("Top Three Calories Carried: ");
  buff.showBuff();
  printf("\nSum: %d\n", buff[0]+buff[1]+buff[2]);

  return 0;
}
