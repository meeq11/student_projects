// main_test.cpp
#include <gtest/gtest.h>
#include "functions.cpp"


TEST(FizzBuzzTests, MultipleOf3) {
   EXPECT_EQ(fizzBuzz(3), "Buzz");
   EXPECT_EQ(fizzBuzz(9), "Buzz");
   EXPECT_EQ(fizzBuzz(21), "Buzz");
}

TEST(FizzBuzzTests, MultipleOf5) {
   EXPECT_EQ(fizzBuzz(5), "Fizz");
   EXPECT_EQ(fizzBuzz(10), "Fizz");
   EXPECT_EQ(fizzBuzz(20), "Fizz");
}

TEST(FizzBuzzTests, MultipleOf3And5) {
   EXPECT_EQ(fizzBuzz(15), "FizzBuzz");
   EXPECT_EQ(fizzBuzz(30), "FizzBuzz");
   EXPECT_EQ(fizzBuzz(45), "FizzBuzz");
}

TEST(FizzBuzzTests,


// ... inne testy ...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

