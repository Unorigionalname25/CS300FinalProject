#include "FlashCards.h"
#include <fstream>


/**!
 * Constructor for Flashcard
 * @param sideOne- String @param sideTwo- String
 * @param multipleChoice- bool @param trueFalse- bool
 * @param matching-bool
*/
//! Constructor of Flashcard
Flashcard::Flashcard(const std::string& sideOne, const std::string& sideTwo,
                     bool freeResponse, bool multipleChoice, bool trueFalse, bool matching)
    : sideOne(sideOne), sideTwo(sideTwo),
      freeResponse(freeResponse), multipleChoice(multipleChoice),
      trueFalse(trueFalse), matching(matching) {}
//! getter for side One
/**!
 * @return side one of a flashcard
*/
const std::string& Flashcard::getSideOne() const {
    return sideOne;
}
//! getter for side Two
/**!
 * @return Side two of a flashcard
*/
const std::string& Flashcard::getSideTwo() const {
    return sideTwo;
}
//! Getter for Free Response
/**!
 * @return is free response as bool
*/
bool Flashcard::isFreeResponse() const {
    return freeResponse;
}
//! Getter for multiple choice
/**!
 * @return is multiple choice as bool
*/
bool Flashcard::isMultipleChoice() const {
    return multipleChoice;
}

//! Getter for true false
/**!
 * @return is true or false as bool
*/
bool Flashcard::isTrueFalse() const {
    return trueFalse;
}
//! Getter for Matchin
/**!
 * @return is matching as bool
*/
bool Flashcard::isMatching() const {
    return matching;
}
//! Function to add a card
/**!
 * adds a card to a card set
 * @param card to add
*/
void FlashcardSet::addCard(const Flashcard& card) {
    flashcards.push_back(card);
}
//! Helper function for reading file
/**!
 * Helper function for reading file
 * @param inp string input
 * @return bool
*/
bool isbool(std::string inp){
    if(inp == "true") return true;
    return false;
}


//! Function that saves card set to a file
/**!
 * @param path string path of file
 * @param cards vector of flashcards
 * takes inputs and saves them to a file
*/
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

//! Getter of vector of flashcards
/**
 * @return vector of flashcards
*/
const std::vector<Flashcard>& FlashcardSet::getFlashcards() const {
    return flashcards;
}
