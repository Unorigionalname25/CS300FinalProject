#include "FlashCards.h"
#include <iostream>

int main() {
    // Example usage
    Flashcard card1("What is the capital of France?", "Paris", true, false, false, false);
    Flashcard card2("2 + 2", "4", true, true, false, false);
    Flashcard card3("Is the sky blue?", "Yes", false, false, true, false);

    FlashcardSet cardSet;
    cardSet.addCard(card1);
    cardSet.addCard(card2);
    cardSet.addCard(card3);

    // Accessing flashcards in the set
    const std::vector<Flashcard>& flashcards = cardSet.getFlashcards();

    // Example: Print details of each flashcard
    for (const Flashcard& card : flashcards) {
        std::cout << "Question: " << card.getSideOne() << std::endl;
        std::cout << "Answer: " << card.getSideTwo() << std::endl;
        std::cout << "Free Response: " << (card.isFreeResponse() ? "Yes" : "No") << std::endl;
        std::cout << "Multiple Choice: " << (card.isMultipleChoice() ? "Yes" : "No") << std::endl;
        std::cout << "True/False: " << (card.isTrueFalse() ? "Yes" : "No") << std::endl;
        std::cout << "Matching: " << (card.isMatching() ? "Yes" : "No") << std::endl;
        std::cout << "---------------------" << std::endl;
    }

    return 0;
}
