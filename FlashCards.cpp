#include "FlashCards.h"
#include <fstream>

Flashcard::Flashcard(const std::string& sideOne, const std::string& sideTwo,
                     bool freeResponse, bool multipleChoice, bool trueFalse, bool matching)
    : sideOne(sideOne), sideTwo(sideTwo),
      freeResponse(freeResponse), multipleChoice(multipleChoice),
      trueFalse(trueFalse), matching(matching) {}

const std::string& Flashcard::getSideOne() const {
    return sideOne;
}

const std::string& Flashcard::getSideTwo() const {
    return sideTwo;
}

bool Flashcard::isFreeResponse() const {
    return freeResponse;
}

bool Flashcard::isMultipleChoice() const {
    return multipleChoice;
}

bool Flashcard::isTrueFalse() const {
    return trueFalse;
}

bool Flashcard::isMatching() const {
    return matching;
}

void FlashcardSet::addCard(const Flashcard& card) {
    flashcards.push_back(card);
}

bool isbool(std::string inp){
    if(inp == "true") return true;
    return false;
}



void FlashcardSet::saveFile(std::string path, std::vector<Flashcard>& cards){
    std::ofstream ofs(path, std::ofstream::trunc);
    for(Flashcard card : cards){
        ofs << card.getSideOne() << ",";
        ofs << card.getSideTwo() << ",";
        ofs << card.isFreeResponse() << ",";
        ofs << card.isMultipleChoice() << ",";
        ofs << card.isTrueFalse() << ",";
        ofs << card.isMatching() << std::endl;
    }
}


const std::vector<Flashcard>& FlashcardSet::getFlashcards() const {
    return flashcards;
}
