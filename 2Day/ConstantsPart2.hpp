#include <stdint.h>
#include <string>

namespace CONSTANTS {
  namespace SCORE {
    uint8_t ROCK = 1;
    uint8_t PAPER = 2;
    uint8_t SCISSORS = 3;
    uint8_t LOSS = 0;
    uint8_t DRAW = 3;
    uint8_t WIN = 6;
  }

  namespace ROCK {
    const char CHALLENGE = 'A';
    const int WINRESPONSE = SCORE::PAPER;
    const int DRAWRESPONSE = SCORE::ROCK;
    const int LOSSRESPONSE = SCORE::SCISSORS;
  };

  namespace PAPER {
    const char CHALLENGE = 'B';
    const int WINRESPONSE = SCORE::SCISSORS;
    const int DRAWRESPONSE = SCORE::PAPER;
    const int LOSSRESPONSE = SCORE::ROCK;
  };

  namespace SCISSORS {
    const char CHALLENGE = 'C';
    const int WINRESPONSE = SCORE::ROCK;
    const int DRAWRESPONSE = SCORE::SCISSORS;
    const int LOSSRESPONSE = SCORE::PAPER;
  };

  namespace OUTCOME {
    const char LOSS = 'X';
    const char DRAW = 'Y';
    const char WIN = 'Z';
  }
}
