//
// Created by ekaterina on 26.02.2022.
//

#include <stdexcept>
#include <gtest/gtest.h>
#include <task2.hpp>

class Data {
 public:
  int num;
  std::string str;
  Data() = default;
  Data(int n, std::string s) : num(n), str(s) {}
  Data(const Data& value) = delete;
  Data(Data&& value) noexcept = default;
  auto operator=(const Data& value) -> Data& = delete;
  auto operator=(Data&& value) noexcept -> Data& = default;
};

TEST(Stack2, CorrectClassTest) {
  EXPECT_TRUE(std::is_move_constructible<Data>::value);
  EXPECT_TRUE(std::is_move_assignable<Data>::value);
  EXPECT_FALSE(std::is_copy_constructible<Data>::value);
  EXPECT_FALSE(std::is_copy_assignable<Data>::value);
}

TEST(Stack2, PushTest) {
  Stack2<Data> s;
  EXPECT_EQ(s.stack_size(), 0);
  EXPECT_ANY_THROW(s.head());
  Data item(5, "c++");
  s.push(std::move(item));
  EXPECT_EQ(s.head().num, 5);
  EXPECT_EQ(s.head().str, "c++");
  EXPECT_EQ(s.stack_size(), 1);
}

TEST(Stack2, PushEmplanceTest) {
  Stack2<Data> s;
  EXPECT_EQ(s.stack_size(), 0);
  EXPECT_ANY_THROW(s.head());
  s.push_emplace(1000, "World");
  EXPECT_EQ(s.head().num, 1000);
  EXPECT_EQ(s.head().str, "World");
  EXPECT_EQ(s.stack_size(), 1);
  s.push_emplace(56789, "stack");
  EXPECT_EQ(s.head().num, 56789);
  EXPECT_EQ(s.head().str, "stack");
  EXPECT_EQ(s.stack_size(), 2);
}

TEST(Stack2, PopTest) {
  Stack2<Data> s;
  EXPECT_EQ(s.stack_size(), 0);
  EXPECT_ANY_THROW(s.head());
  Data item(5, "c++");
  s.push(std::move(item));
  s.push_emplace(1000, "World");
  s.pop();
  EXPECT_EQ(s.stack_size(), 1);
  EXPECT_EQ(s.head().num, 5);
  EXPECT_EQ(s.head().str, "c++");
  Data d = s.pop();
  EXPECT_EQ(d.num, 5);
  EXPECT_EQ(d.str, "c++");
  EXPECT_EQ(s.stack_size(), 0);
  EXPECT_ANY_THROW(s.head());
}

TEST(Stack2, MoveTest) {
  EXPECT_TRUE(std::is_move_constructible<Stack2<int>>::value);
  EXPECT_TRUE(std::is_move_constructible<Stack2<std::string>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack2<int>>::value);
  EXPECT_TRUE(std::is_move_assignable<Stack2<std::string>>::value);
}

TEST(Stack2, CopyTest) {
  EXPECT_FALSE(std::is_copy_constructible<Stack2<int>>::value);
  EXPECT_FALSE(std::is_copy_constructible<Stack2<std::string>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack2<int>>::value);
  EXPECT_FALSE(std::is_copy_assignable<Stack2<std::string>>::value);
}
