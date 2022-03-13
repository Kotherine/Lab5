// Copyright 2021 Your Name <your_email>

#include <stdexcept>
#include <gtest/gtest.h>
#include <task1.hpp>

TEST(Stack1, PushTest) {
  Stack1<int> s;
  EXPECT_EQ(s.stack_size(), 0);
  s.push(1);
  EXPECT_EQ(s.stack_size(), 1);
  EXPECT_EQ(s.head(), 1);
  s.push(11);
  EXPECT_EQ(s.stack_size(), 2);
  EXPECT_EQ(s.head(), 11);
}

TEST(Stack1, PopTest) {
  Stack1<int> s;
  EXPECT_EQ(s.stack_size(), 0);
  EXPECT_ANY_THROW(s.head());
  s.push(1);
  s.push(2);
  s.pop();
  EXPECT_EQ(s.stack_size(), 1);
  EXPECT_EQ(s.head(), 1);
  s.pop();
  EXPECT_ANY_THROW(s.pop());
}

TEST(Stack1, MoveTest) {
  EXPECT_TRUE(std::is_move_constructible<Stack1<int>>::value);
  EXPECT_TRUE(std::is_move_constructible<Stack1<std::string>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack1<int>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack1<std::string>>::value);
}

TEST(Stack1, CopyTest) {
  EXPECT_FALSE(std::is_copy_constructible<Stack1<int>>::value);
  EXPECT_FALSE(std::is_copy_constructible<Stack1<std::string>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack1<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack1<std::string>>::value);
}