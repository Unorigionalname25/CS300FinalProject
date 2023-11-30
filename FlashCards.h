#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <string>
#include <vector>

class Flashcard {
public:
    Flashcard(const std::string& sideOne, const std::string& sideTwo,
              bool freeResponse, bool multipleChoice, bool trueFalse, bool matching);

    // Getter methods
    const std::string& getSideOne() const;
    const std::string& getSideTwo() const;
    bool isFreeResponse() const;
    bool isMultipleChoice() const;
    bool isTrueFalse() const;
    bool isMatching() const;

private:
    std::string sideOne;
    std::string sideTwo;
    bool freeResponse;
    bool multipleChoice;
    bool trueFalse;
    bool matching;
};

class FlashcardSet {
public:
    // Add a new flashcard to the set
    void addCard(const Flashcard& card);

    // Retrieve the vector of flashcards
    const std::vector<Flashcard>& getFlashcards() const;

private:
    std::vector<Flashcard> flashcards;
};

#endif // FLASHCARD_H
