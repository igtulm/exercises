#include "wordsparser.h"
#include <gtest/gtest.h>
#include <algorithm>

class TestWordsParser : public ::testing::Test {
 public:
  TestWordsParser() {}
  ~TestWordsParser() override {}

  void SetUp() override {}
  void TearDown() override {}

 protected:
  std::vector<std::string> words{"The",  "time",   "has",  "come",
                                 "the",  "walrus", "said", "to",
                                 "talk", "of",     "many", "things"};

  std::string sentence =
      "The time has come, the walrus said, to talk of many things";
};

TEST_F(TestWordsParser, shouldParseWords) {
  freqdict::WordsParser wp(sentence);

  std::vector<std::string> wpWords;
  wpWords.reserve(words.size());

  for (auto it : wp) {
    wpWords.push_back(it);
  }

  ASSERT_EQ(words.size(), wpWords.size());
  for (std::size_t i = 0; i < wpWords.size(); ++i) {
    ASSERT_STREQ(words[i].c_str(), wpWords[i].c_str());
  }
}

TEST_F(TestWordsParser, shouldParseWordsCaseInsensitive) {
  freqdict::WordsParser wp(sentence, true);

  std::vector<std::string> wpWords;
  wpWords.reserve(words.size());

  for (auto it : wp) {
    wpWords.push_back(it);
  }

  ASSERT_EQ(words.size(), wpWords.size());
  for (std::size_t i = 0; i < wpWords.size(); ++i) {
    std::string word = words[i];
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    ASSERT_STREQ(word.c_str(), wpWords[i].c_str());
  }
}

TEST_F(TestWordsParser, shouldParseWordsWithNotALetterInEndOfString) {
  freqdict::WordsParser wp(sentence + ".");

  std::vector<std::string> wpWords;
  wpWords.reserve(words.size());

  for (auto it : wp) {
    wpWords.push_back(it);
  }

  ASSERT_EQ(words.size(), wpWords.size());
  for (std::size_t i = 0; i < wpWords.size(); ++i) {
    ASSERT_STREQ(words[i].c_str(), wpWords[i].c_str());
  }
}
