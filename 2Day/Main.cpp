#include "Constants.hpp"
#include <iostream>
#include <fstream>

/*
* CONSTANTS
*/
#define FILE_PATH "input.txt"
// index of char positions in input file strings
#define CHALLENGEIDX   0
#define RESPONSEIDX  2

using namespace CONSTANTS;

int roundScore(std::string line) {
  // ASSERT: you are response
  char chal = line[CHALLENGEIDX];
  char resp = line[RESPONSEIDX];

  int result=-1;
  switch(chal) {
    case ROCK::CHALLENGE:
        if(resp==ROCK::RESPONSE) result = CONSTANTS::SCORE::DRAW;
        if(resp==PAPER::RESPONSE) result = CONSTANTS::SCORE::WIN;
        if(resp==SCISSORS::RESPONSE) result = CONSTANTS::SCORE::LOSS;
      break;
    case PAPER::CHALLENGE:
        if(resp==ROCK::RESPONSE) result = CONSTANTS::SCORE::LOSS;
        if(resp==PAPER::RESPONSE) result = CONSTANTS::SCORE::DRAW;
        if(resp==SCISSORS::RESPONSE) result = CONSTANTS::SCORE::WIN;
      break;
    case SCISSORS::CHALLENGE:
        if(resp==ROCK::RESPONSE) result = CONSTANTS::SCORE::WIN;
        if(resp==PAPER::RESPONSE) result = CONSTANTS::SCORE::LOSS;
        if(resp==SCISSORS::RESPONSE) result = CONSTANTS::SCORE::DRAW;
      break;
  }


  // std::cout << toString(chal) << " " << toString(resp) << " -> " << result;
  return result;
}

int shapeScore(std::string line) {
  // ASSERT: you are response
  char resp = line[RESPONSEIDX];

  int result=-1;
  if(resp==ROCK::RESPONSE) result = CONSTANTS::SCORE::ROCK;
  if(resp==PAPER::RESPONSE) result = CONSTANTS::SCORE::PAPER;
  if(resp==SCISSORS::RESPONSE) result = CONSTANTS::SCORE::SCISSORS;

  // std::cout << " + " << result << std::endl;


  return result;
}

int main() {

  std::ifstream f;
  std::string line;

  // Access file
  f.open(FILE_PATH);
  if( !f.is_open() ) {
    return -1;
  }

  // Parse
  int totalScore =0;
  while( getline(f, line) ) {
    totalScore += shapeScore(line) + roundScore(line);
  }
  
  std::cout << "total score: " << totalScore << std::endl;
  f.close();
  return 0;
}
