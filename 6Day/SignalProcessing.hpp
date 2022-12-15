#ifndef SIGNAL_PROCESSING_HPP
#define SIGNAL_PROCESSING_HPP

namespace SignalProcessing {

    /* Manages memory of most recent characters seen

      UniqueSequenceIdentifier keeps track of bulk-character existence, so this module only needs to remember the oldest character seen
      Has a warm up time where one to all elements are invalid characters
    */
    class CharMemory {
      char record[4];
      int curr;       // Always points to oldest element
    public:
      CharMemory();
      char getOldest();
      void replaceOldest(char newChar);
      bool isReady();
    };

    /* Identifies whether most recent sequence of numbers has any duplicates

      shall assume only characters appearing are alphabetic characters a-z and A-Z
      shall tally occurrences of each character it handles
      shall operate independent of its window size (for our instance, window size = 4 characters)
    */
    class UniqueSequenceIdentifier {
      CharMemory recentCharacters;
      int characterRecord[26 * 2]; // 52 possible characters present
    public:
      UniqueSequenceIdentifier(CharMemory memory);
      void registerChar(char newChar);
      bool allUnique();
    };


}

#endif
