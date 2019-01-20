#include <gtest/gtest.h>
#include "charnoder.h"

 class TestCharNoder : public ::testing::Test {
 public:
  TestCharNoder() {}
  ~TestCharNoder() override {}

  void SetUp() override {}
  void TearDown() override {}
};

 TEST_F(TestCharNoder, shouldPutAndGetCorrectDataByAlphaIndex) {
  freqdict::CharNoder<char> cn;

  for (char c = 'a'; c <= 'z'; c++) {
    cn[c] = c;
  }

  for (char c = 'A'; c <= 'Z'; c++) {
    cn[c] = c;
  }

  for (auto it : cn) {
   ASSERT_EQ(it.first, it.second);
  }
}
