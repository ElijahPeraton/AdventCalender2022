#ifndef PRIORITY_H
#define PRIORITY_H

#include <iostream>
#include <string>

// a-z shall have priorities 1-26
// A-Z shall have priorities 27-52

// int('a') = 97
// int('z') = 122
// int('A') = 65
// int('Z') = 90

namespace Priority {


  int calculateFromChar(char c) {
    int asInt = c;
    bool isUpperCase;
    int offset;

    isUpperCase = asInt<91;
    if(isUpperCase) offset = 38;
    else            offset = 96;

    asInt -= offset;
    return asInt;
  }


  char toChar(int integer) {
    bool isUpperCase = integer >= 27;
    if(isUpperCase) return (char) (integer+38);
    else return (char) (integer+96);
  }


}

#endif
