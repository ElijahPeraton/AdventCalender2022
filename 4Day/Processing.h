#include <string>
#include <iostream>

namespace Processing {

  // arr int[] of size 4
  void lineToIntArray(std::string line, int *arr) {
    int idx0, idx1, idx2, idx3;
    idx0 = 0;
    idx1 = line.find("-", idx0)+1; // Taking advantage of pos parameter
    idx2 = line.find(",", idx1)+1;
    idx3 = line.find("-", idx2)+1;

    arr[0] = std::stoi(line.substr(idx0, (idx1-idx0-1)));
    arr[1] = std::stoi(line.substr(idx1, (idx2-idx1-1)));
    arr[2] = std::stoi(line.substr(idx2, (idx3-idx2-1)));
    arr[3] = std::stoi(line.substr(idx3));
  }

}