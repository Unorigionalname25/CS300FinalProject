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

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}