#include "SignalProcessing.hpp"
#include <iostream>

using namespace SignalProcessing;

#define INVALID_CHAR '?'

//  Helper function
// Convert character 'a-z,A-Z' to index 0 through 51
int charToIndex(char c) {
  int asInt = c;
  bool isUpperCase;
  int offset;

  // Empirically determined values
  isUpperCase = asInt<91;
  if(isUpperCase) offset = 39;
  else            offset = 97;

  asInt -= offset;
  return asInt;
}


/*
*
*   Char Memory
*
*/
CharMemory::CharMemory() :
  curr(0),
  record{INVALID_CHAR,INVALID_CHAR,INVALID_CHAR,INVALID_CHAR}{
}

char CharMemory::getOldest() {
  return record[curr];
}

void CharMemory::replaceOldest(char newChar) {
  // Replace oldest element
  // update curr pointer
  // if curr pointer has wrapped around, record is full -> Ready for use
  record[curr] = newChar;
  curr += 1;
  curr %= 4;
}

bool CharMemory::isReady() {
  bool filled = record[curr] != INVALID_CHAR;
  return filled;
}


/*
*
*   Unique Sequence Identifier
*
*/
UniqueSequenceIdentifier::UniqueSequenceIdentifier(CharMemory memory) : recentCharacters(memory), characterRecord{ } {
}

void UniqueSequenceIdentifier::registerChar(char newChar) {
  // Increment record of new character
  // Decrement record of old character
  // ASSERT: old character may be invalid character if memory still warming up
  char oldChar = recentCharacters.getOldest();
  recentCharacters.replaceOldest(newChar);

  characterRecord[ charToIndex(newChar) ]++; // increment new value

  if(oldChar==INVALID_CHAR) return;

  characterRecord[ charToIndex(oldChar) ]--; // decrement old value
}

bool UniqueSequenceIdentifier::allUnique() {
  // Go through record of existing characters
  // if record greater than 1 -> repeated character. fail all

  bool invalidRequest = !recentCharacters.isReady();
  if(invalidRequest) return false;

  for(int i=0; i<52; i++) {
    bool repeated = characterRecord[i] > 1;
    if(repeated) return false;
  }

  return true;
}
