#include "ConstantsPart2.hpp"
#include <iostream>
#include <fstream>

/*
* CONSTANTS
*/
#define FILE_PATH "input.txt"
// index of char positions in input file strings
#define CHALLENGEIDX   0
#define OUTCOMEIDX  2

using namespace CONSTANTS;

int roundScore(std::string line) {
  // ASSERT: you are response
  char outcome = line[OUTCOMEIDX];

  int result=-1;
  if(outcome==OUTCOME::LOSS) result = SCORE::LOSS;
  if(outcome==OUTCOME::DRAW) result = SCORE::DRAW;
  if(outcome==OUTCOME::WIN) result = SCORE::WIN;

  return result;
}

int shapeScore(std::string line) {
  // ASSERT: you are response
  char chal = line[CHALLENGEIDX];
  char outcome = line[OUTCOMEIDX];

  int result=-1;
  switch(chal) {
    case ROCK::CHALLENGE:
        if(outcome==OUTCOME::LOSS) result = ROCK::LOSSRESPONSE;
        if(outcome==OUTCOME::DRAW) result = ROCK::DRAWRESPONSE;
        if(outcome==OUTCOME::WIN)  result = ROCK::WINRESPONSE;
      break;
    case PAPER::CHALLENGE:
        if(outcome==OUTCOME::LOSS) result = PAPER::LOSSRESPONSE;
        if(outcome==OUTCOME::DRAW) result = PAPER::DRAWRESPONSE;
        if(outcome==OUTCOME::WIN)  result = PAPER::WINRESPONSE;
      break;
    case SCISSORS::CHALLENGE:
        if(outcome==OUTCOME::LOSS) result = SCISSORS::LOSSRESPONSE;
        if(outcome==OUTCOME::DRAW) result = SCISSORS::DRAWRESPONSE;
        if(outcome==OUTCOME::WIN)  result = SCISSORS::WINRESPONSE;
      break;
  }

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
