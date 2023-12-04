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

void FlashcardSet::readFile(std::string path){
    std::vector<Flashcard> card;
    std::fstream myfile;
    myfile.open(path);
    std::string str;
    std::string temp[6];
    int i = 0;
    while(std::getline(myfile, str, ',')){
        temp[i] = str;
        if(i == 5){
            card.push_back(Flashcard(temp[0],temp[1],isbool(temp[2]),isbool(temp[3]),isbool(temp[4]),isbool(temp[5])));
        }
    }
    flashcards = card;
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
