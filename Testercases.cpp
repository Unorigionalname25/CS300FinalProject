#include "FlashCards.h"
#include <gtest/gtest.h>

TEST(FlashcardTest, CorrectAnswer) {
    Flashcard card("What is the capital of France?", "Paris", true, false, false, false);
    EXPECT_EQ(card.getSideTwo(), "Paris");
}

TEST(FlashcardSetTest, AddCard) {
    FlashcardSet cardSet;
    Flashcard card("Question", "Answer", true, false, false, false);
    cardSet.addCard(card);
    const std::vector<Flashcard>& flashcards = cardSet.getFlashcards();
    EXPECT_EQ(flashcards.size(), 1);
    EXPECT_EQ(flashcards[0].getSideOne(), "Question");
    EXPECT_EQ(flashcards[0].getSideTwo(), "Answer");
}

TEST(FlashcardTest, IsFreeResponse) {
    Flashcard card("Question", "Answer", true, false, false, false);
    EXPECT_TRUE(card.isFreeResponse());
    EXPECT_FALSE(card.isMultipleChoice());
}

TEST(FlashcardTest, IsMultipleChoice) {
    Flashcard card("Question", "Answer", false, true, false, false);
    EXPECT_TRUE(card.isMultipleChoice());
    EXPECT_FALSE(card.isFreeResponse());
}

TEST(FlashcardSetTest, GetFlashcards) {
    FlashcardSet cardSet;
    Flashcard card1("Q1", "A1", true, false, false, false);
    Flashcard card2("Q2", "A2", false, true, false, false);
    cardSet.addCard(card1);
    cardSet.addCard(card2);

    const std::vector<Flashcard>& flashcards = cardSet.getFlashcards();
    ASSERT_EQ(flashcards.size(), 2);

    EXPECT_EQ(flashcards[0].getSideOne(), "Q1");
    EXPECT_EQ(flashcards[0].getSideTwo(), "A1");
    EXPECT_EQ(flashcards[1].getSideOne(), "Q2");
    EXPECT_EQ(flashcards[1].getSideTwo(), "A2");
}

// Test if the FlashcardSet correctly handles an empty set
TEST(FlashcardSetTest, EmptySet) {
    FlashcardSet cardSet;
    const std::vector<Flashcard>& flashcards = cardSet.getFlashcards();
    EXPECT_TRUE(flashcards.empty());
}

// Test multiple-choice flashcards in the set
TEST(FlashcardSetTest, MultipleChoiceCards) {
    FlashcardSet cardSet;
    Flashcard card1("Q1", "A1", false, true, false, false);
    Flashcard card2("Q2", "A2", false, true, false, false);
    cardSet.addCard(card1);
    cardSet.addCard(card2);

    const std::vector<Flashcard>& flashcards = cardSet.getFlashcards();
    ASSERT_EQ(flashcards.size(), 2);

    EXPECT_TRUE(flashcards[0].isMultipleChoice());
    EXPECT_TRUE(flashcards[1].isMultipleChoice());
    EXPECT_FALSE(flashcards[0].isFreeResponse());
    EXPECT_FALSE(flashcards[1].isFreeResponse());
}

// Test a mix of different question types
TEST(FlashcardSetTest, MixedQuestionTypes) {
    FlashcardSet cardSet;
    Flashcard card1("Q1", "A1", true, false, false, false);
    Flashcard card2("Q2", "A2", false, true, false, false);
    Flashcard card3("Q3", "A3", false, false, true, false);
    cardSet.addCard(card1);
    cardSet.addCard(card2);
    cardSet.addCard(card3);

    const std::vector<Flashcard>& flashcards = cardSet.getFlashcards();
    ASSERT_EQ(flashcards.size(), 3);

    EXPECT_TRUE(flashcards[0].isFreeResponse());
    EXPECT_TRUE(flashcards[1].isMultipleChoice());
    EXPECT_TRUE(flashcards[2].isTrueFalse());
}

// Test adding and retrieving a large number of flashcards
TEST(FlashcardSetTest, LargeNumberOfFlashcards) {
    FlashcardSet cardSet;
    const int numCards = 1000;

    for (int i = 0; i < numCards; ++i) {
        Flashcard card("Q" + std::to_string(i), "A" + std::to_string(i), true, false, false, false);
        cardSet.addCard(card);
    }

    const std::vector<Flashcard>& flashcards = cardSet.getFlashcards();
    ASSERT_EQ(flashcards.size(), numCards);

    // Verify the content of a few randomly chosen cards
    EXPECT_EQ(flashcards[123].getSideOne(), "Q123");
    EXPECT_EQ(flashcards[456].getSideTwo(), "A456");
    EXPECT_EQ(flashcards[789].isFreeResponse(), true);
}

// Test case for incorrect answer
TEST(FlashcardTest, IncorrectAnswer) {
    Flashcard card("What is the capital of France?", "Paris", true, false, false, false);
    EXPECT_NE(card.getSideTwo(), "London");
}

TEST(FlashcardTest, IncorrectAnswerNumbers) {
    Flashcard card("What is the capital of France?", "Paris", true, false, false, false);
    EXPECT_NE(card.getSideTwo(), "2056");
}

// Test case for incorrect answer (different country)
TEST(FlashcardTest, IncorrectAnswerDifferentCountry) {
    Flashcard card("What is the capital of France?", "Paris", true, false, false, false);
    EXPECT_NE(card.getSideTwo(), "UnitedStates");
}


// Test for correct answer to a true/false question
TEST(FlashcardTest, TrueFalseCorrectAnswer) {
    Flashcard card("The sun rises in the east.", "True", false, false, true, false);
    EXPECT_EQ(card.getSideTwo(), "True");
}

// Test for incorrect answer to a true/false question
TEST(FlashcardTest, TrueFalseIncorrectAnswer) {
    Flashcard card("The capital of Japan is Beijing.", "False", false, false, true, false);
    EXPECT_NE(card.getSideTwo(), "True");
}

TEST(FlashcardTest, MatchingQuestion) {
    Flashcard card("Match the countries with their capitals.", "Paris - France", false, false, false, true);
    EXPECT_TRUE(card.isMatching());
    EXPECT_EQ(card.getSideTwo(), "Paris - France");
}



int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}