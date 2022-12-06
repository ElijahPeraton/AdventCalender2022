#ifndef PROCESSING_H
#define PROCESSING_H

#include <string>
#include <iostream>
#include "Priority.h"

#define EXISTS 1
#define CHAR_TO_ARRAY_INDEX(inputChar) (Priority::calculateFromChar(inputChar) - 1)
#define PRINT_LUT  std::cout<<"[ "; for(int i=0;i<52;i++) { std::cout<<LUT[i]<<" "; } std::cout<<"]"<<std::endl;

namespace Processing {


  /**
    First half shall form lookup table (52 array [a-z,A-Z])
    Second half shall use loopup table
   **/
  char findRepeat(std::string input) {

    int firstHalfLUT[52] = {}; // Aggregate initialization to 0
    std::string low, high;
    int mid;

    mid = input.length() / 2;
    low = input.substr(0,mid);
    high = input.substr(mid/*to end*/);

    // Debug
    std::cout << low << " | " << high << " ";


    // Generate table of existing characters
    for(int i=0; i<mid; i++) {
      // Mark as existing
      firstHalfLUT[ CHAR_TO_ARRAY_INDEX(low[i]) ] = EXISTS;
    }


    // Query table
    for(int i=0; i<mid; i++) {
      char c = high[i];
      bool isRepeated = firstHalfLUT[CHAR_TO_ARRAY_INDEX(c)]==EXISTS;
      if( isRepeated ) {
        // Debug
        std::cout << "- " << c << std::endl;
        return c; // Success, exit
      }
    }

    return '#'; // Repeat never found
  }


  /**
    Go through line1, mark every letter which appears in 1 '1'
    Go through line2, only mark letters '2' when it has been marked '1' before
    Go through line3, only mark letters '3' when it has been marked '2' before

    By definition of problem, there should be one, single '3' at the end
  **/
  char findGroupRepeat(std::string line1, std::string line2, std::string line3) {

    int LUT[52] = {}; // Aggregate initialization to 0

    /**   Line 1
    **/
    for(int idx=line1.length()-1; idx>-1; idx--) {
      // Mark as existing
      LUT[ CHAR_TO_ARRAY_INDEX(line1[idx]) ] = 1;
    }

    /**   Line 2
    **/
    for(int idx=line2.length()-1; idx>-1; idx--) {
      int *spot = &LUT[CHAR_TO_ARRAY_INDEX(line2[idx])];
      if( *spot==1 ) *spot=2;
    }

    /**   Line 3
    **/
    for(int idx=line3.length()-1; idx>-1; idx--) {
      int *spot = &LUT[CHAR_TO_ARRAY_INDEX(line3[idx])];
      if( *spot==2 ) *spot=3;
    }
    PRINT_LUT;

    /**   Searching
    **/
    for(int idx=0; idx<52; idx++) {
      if(LUT[idx]==3) return Priority::toChar(idx+1);
    }

    return '#';
  }


}

#endif
