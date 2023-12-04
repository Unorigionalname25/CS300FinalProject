#include "FlashCards.h"
#include <iostream>
#include <cstdlib> 


FlashcardSet cardSet;

void createDeck(){
    std::string num;
    std::string side1;
    std::string side2;
    bool free = false;
    bool mult = false;
    bool true_false = false;
    bool match = false;;
    std::cout << "How many cards would you like to have" << std::endl;
    std::cin >> num;
    int i = stoi(num);
    for(int j = 0; j < i; j++){
        std::cout << "What is side 1?" << std::endl;
        std::cin >> side1;
        std::cout << "What is side 2" << std::endl;
        std::cin >> side2;
        std::cout << "Input 1 for Free Response, anything else will be false" << std::endl;
        std::cin >> num;
        if(stoi(num) == 1) free = true;
        std::cout << "Input 1 for Multiple Choice, anything else will be false" << std::endl;
        std::cin >> num;
        if(stoi(num) == 1) mult = true;
        std::cout << "Input 1 for True or False, anything else will be false" << std::endl;
        std::cin >> num;
        if(stoi(num) == 1) true_false = true;
        std::cout << "Input 1 for Matching, anything else will be false" << std::endl;
        std::cin >> num;
        if(stoi(num) == 1) match = true;
        Flashcard temp(side1,side2,free,mult,true_false,match);
        cardSet.addCard(temp);
    }
}

void reviewCards(){
    std::vector<Flashcard> cards = cardSet.getFlashcards();
    int i = 0;
    std::string in;
    std::string info;
    info = cards[i].getSideOne();
    while(true)
    {
        std::cout << "This is the card " << i+1 << std::endl;
        std::cout << info << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "1: Flip card" << std::endl;
        std::cout << "2: Next card" << std::endl;
        std::cout << "3: Quit" << std::endl;
        std::cin >> in;
        if(stoi(in) == 1){
            if(info == cards[i].getSideOne()){
                info = cards[i].getSideTwo();
            } else info = cards[i].getSideOne();
        }else if(stoi(in) == 2){
            i++;
            if(i >= cards.size()){
                i = 0;
            }
            info = cards[i].getSideOne();
        }else if(stoi(in) == 3){
            break;
        }
        else continue;
    }
    
}

void test(){
    std::vector<Flashcard> cards = cardSet.getFlashcards();
    std::string in;
    std::vector<Flashcard> matchingCards;
    for(int i = 0; i < cards.size(); i++){
        int rand = std::rand() % 4;
        switch (rand)
        {
        case 1:
            if(cards[i].isFreeResponse() == true){
                std::cout << "The Question is:" << std::endl;
                std::cout << cards[i].getSideOne() << std::endl;
                std::cout<< "---------------------" << std::endl;
                std::cout << "Please input your answer" << std::endl;
                std::cin >> in;
                if(in == cards[i].getSideTwo()){
                    std::cout << "Correct!" << std::endl;
                } else std::cout << "Sorry, Incorrect." << std::endl;
            }
            break;
        
        case 2:
            if(cards[i].isMatching() == true){
                matchingCards.push_back(cards[i]);
            }
            break;
        case 3:
        /*Did not have time to finish, for now every correct option is Option C
        */
            if(cards[i].isMultipleChoice() == true){
                std::cout << "The Question is:" << std::endl;
                std::cout << cards[i].getSideOne() << std::endl;
                std::cout<< "---------------------" << std::endl;
                std::cout << "A: " << cards[std::rand() % (cards.size()-1)].getSideTwo() << std::endl;
                std::cout << "B: " << cards[std::rand() % (cards.size()-1)].getSideTwo() << std::endl;
                std::cout << "C: " << cards[i].getSideTwo() << std::endl;
                std::cout << "D: " << cards[std::rand() % (cards.size()-1)].getSideTwo() << std::endl;
                std::cout<< "---------------------" << std::endl;
                std::cout << "Please input your answer" << std::endl;
                std::cin >> in;
                if(in != "C") std::cout << "Sorry, Incorrect." << std::endl;
                else std::cout << "Correct!" << std::endl;
            }
        case 4:
            if(cards[i].isTrueFalse() == true){
                std::cout << "The Question is: " <<std::endl << cards[i].getSideOne() << std::endl;
                int o = std::rand() % 2;
                if(o == 0){
                    std::cout << " Does that match this?" << std::endl << cards[i].getSideTwo() << std::endl;
                    std::cin >> in;
                    if(in == "true") std::cout << "Correct!" << std::endl;
                    else std::cout << "False" << std::endl;
                }
            }
        default:
            break;
        }
    }
    /**
     * Also ran out of time to implement this, always correct for now
    */
    if(matchingCards.size() != 0){
        std::cout << "Matching Test" << std::endl;
        std::cout << "-----------------------" << std::endl;
        std::cout << "Please type the matching in the format show below" << std::endl;
        std::cout << "Ex: A B C D  1 2 3 4 ------> A3 B2 C4 D1" << std::endl;
        for(int i = 0; i < matchingCards.size(); i++){
            std::cout << char(65 + i) << ": " << matchingCards[i].getSideOne();
        }
        std::cout << "--------------------" << std::endl;
        for(int i =0; i < matchingCards.size(); i ++){
            if(i+2 < matchingCards.size()){
            std::cout << i << ": " << matchingCards[i+2].getSideTwo() << std::endl; ;
        }else{
            std::cout << i << ": " << matchingCards[matchingCards.size() - i].getSideTwo() << std::endl;
        }
        }
        std::cin >> in;
        std::cout << "Correct!" << std::endl;
    }
}

void useMain(){
    int state = 0;
    std::string input;
    while(true){
    if(state == 0){
        std::cout << "Welcome to our Flash Card Studying tool" << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Select from the options below for what you would like to do" << std::endl;
        std::cout << "1: Create a Deck" << std::endl;
        std::cout << "2: Quit" << std::endl;
        std::cin >> input;
        int temp = stoi(input);
        if(temp == 1){
            createDeck();
            state = 1;
        }else if(temp == 2){
            break;
        }
        else{
            state = 0;
        }
    }if(state == 1){
        std::cout << "Welcome to our Flash Card Studying tool" << std::endl;
        std::cout << "--------------------------------------" << std::endl;
        std::cout << "Select from the options below for what you would like to do" << std::endl;
        std::cout << "1: Review slides" << std::endl;
        std::cout << "2: Test" << std::endl;
        std::cout << "3: Save Deck to file" << std::endl; 
        std::cout << "4: Quit" << std::endl;
        std::cin >> input;
        int temp = stoi(input);
        if(temp == 1){
            reviewCards();
            state = 1;
        }else if(temp == 3){
            std::vector<Flashcard> saved = cardSet.getFlashcards();
            cardSet.saveFile("cards.txt", saved);
            state = 1;
        }else if(temp == 2){
            test();
            state = 1;
        }else if(temp == 4){
            break;}
    }
    }
}



int main() {
    // // Example usage
    // Flashcard card1("What is the capital of France?", "Paris", true, false, false, false);
    // Flashcard card2("2 + 2", "4", true, true, false, false);
    // Flashcard card3("Is the sky blue?", "Yes", false, false, true, false);

    // cardSet.addCard(card1);
    // cardSet.addCard(card2);
    // cardSet.addCard(card3);

    // // Accessing flashcards in the set
    // const std::vector<Flashcard>& flashcards = cardSet.getFlashcards();

    // // Example: Print details of each flashcard
    // for (const Flashcard& card : flashcards) {
    //     std::cout << "Question: " << card.getSideOne() << std::endl;
    //     std::cout << "Answer: " << card.getSideTwo() << std::endl;
    //     std::cout << "Free Response: " << (card.isFreeResponse() ? "Yes" : "No") << std::endl;
    //     std::cout << "Multiple Choice: " << (card.isMultipleChoice() ? "Yes" : "No") << std::endl;
    //     std::cout << "True/False: " << (card.isTrueFalse() ? "Yes" : "No") << std::endl;
    //     std::cout << "Matching: " << (card.isMatching() ? "Yes" : "No") << std::endl;
    //     std::cout << "---------------------" << std::endl;
    // }


    useMain();

    return 0;
}
