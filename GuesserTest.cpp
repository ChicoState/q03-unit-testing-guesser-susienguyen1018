/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};


TEST (GuesserTest, correct_secret){
	Guesser guesser("HiImSusie");
	bool match = guesser.match("HiImSusie");
	ASSERT_EQ(true,match);
}

TEST (GuesserTest, wrong_secret){
	Guesser guesser("HiImSusie");
	bool match = guesser.match("HiImsusie");
	ASSERT_EQ(false,match);
}

TEST (GuesserTest, after_one_wrong_secret){
	Guesser guesser("HiImSusie");
	guesser.match("HiImsusie");
	bool match = guesser.match("HiImSusie");
	ASSERT_EQ(true,match);
}

TEST (GuesserTest, after_two_wrong_secret){
	Guesser guesser("HiImSusie");
	guesser.match("HiImsusie");
	guesser.match("Hiimsusie");
	bool match = guesser.match("HiImSusie");
	ASSERT_EQ(true,match);
}

TEST (GuesserTest, trim_secret){
	Guesser guesser("HiImSusie12345678901234567890123456");
	bool match = guesser.match("HiImSusie12345678901234567890123");
	ASSERT_EQ(true,match);
}

TEST(GuesserTest, three_incorrect_attempts) {
    Guesser guesser("HiImSusie");
    guesser.match("HiImSusiet1"); 
    guesser.match("HiImSusiet2"); 
    guesser.match("HiImSusiet3"); 
    bool match = guesser.match("HiImSusie");
    ASSERT_EQ(false, match); 
}

TEST(GuesserTest, correct_reminding){
    Guesser guesser("HiImSusie");
    int match = guesser.remaining();
    ASSERT_EQ(3, match);
}

TEST(GuesserTest, huge_distance){
    Guesser guesser("HiImSusie");
    guesser.match("HelloWorldHelloWorld");
    int match = guesser.remaining();
    ASSERT_EQ(0, match);
}

TEST(GuesserTest, two_remaining_left){
    Guesser guesser("HiImSusie");
    guesser.match("hiImSusie");
    int match = guesser.remaining();
    ASSERT_EQ(2, match);
}

TEST(GuesserTest, one_remaining_left){
    Guesser guesser("HiImSusie");
    guesser.match("hiImSusie");
    guesser.match("iiimSusie");
    int match = guesser.remaining();
    ASSERT_EQ(1, match);
}

TEST(GuesserTest, zero_remaining_left){
    Guesser guesser("HiImSusie");
    guesser.match("HiImSusie1");
    guesser.match("HiImSusie2");
    guesser.match("HiImSusie3");
    int match = guesser.remaining();
    ASSERT_EQ(0, match);
}

TEST(GuesserTest, empty_secret) {
    Guesser guesser("");
    bool match = guesser.match("HiImSusie");
    ASSERT_EQ(false, match);
}

TEST(GuesserTest, empty_guess) {
    Guesser guesser("HiImSusie");
    bool match = guesser.match("");
    ASSERT_EQ(false, match); 
}

TEST(GuesserTest, empty_with_empty) {
    Guesser guesser("");
    bool match = guesser.match("");
    ASSERT_EQ(true, match); 
}

TEST(GuesserTest, no_decrement_on_correct_guess) {
    Guesser guesser("HiImSusie");
    guesser.match("HiImSusie");
    guesser.match("HiImSusie");
    int match = guesser.remaining();
    ASSERT_EQ(3, match); 
}


