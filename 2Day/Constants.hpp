#include <stdint.h>
#include <string>

namespace CONSTANTS {

  namespace ROCK {
    const char CHALLENGE = 'A';
    const char RESPONSE = 'X';
  };

  namespace PAPER {
    const char CHALLENGE = 'B';
    const char RESPONSE = 'Y';
  };

  namespace SCISSORS {
    const char CHALLENGE = 'C';
    const char RESPONSE = 'Z';
  };

  namespace SCORE {
    uint8_t ROCK = 1;
    uint8_t PAPER = 2;
    uint8_t SCISSORS = 3;
    uint8_t LOSS = 0;
    uint8_t DRAW = 3;
    uint8_t WIN = 6;
  }

  static std::string toString(char c) {
    if( c==ROCK::CHALLENGE || c==ROCK::RESPONSE ) return "ROCK";
    if( c==PAPER::CHALLENGE || c==PAPER::RESPONSE ) return "PAPER";
    if( c==SCISSORS::CHALLENGE || c==SCISSORS::RESPONSE ) return "SCISSORS";
    return "DEFAULT";
  }
}
