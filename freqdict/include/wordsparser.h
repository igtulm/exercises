#pragma once

#include <string.h>
#include <string>

namespace freqdict {

const unsigned wordMaxSize = 512;

class WordsParser {
 public:
  WordsParser(const char *str, bool isInsensitive = false)
      : str_(str), sz_(strlen(str)), isInsensitive_(isInsensitive) {}
  WordsParser(const std::string &str, bool isInsensitive = false)
      : str_(&str[0]), sz_(str.size()), isInsensitive_(isInsensitive) {}
  ~WordsParser() {}

  class Iterator {
   public:
    Iterator(const char *pos, bool isInsensitive = false)
        : startPos_(pos), pos_(pos), isInsensitive_(isInsensitive) {}
    Iterator(const char *startPos, const char *pos, bool isInsensitive = false)
        : startPos_(startPos), pos_(pos), isInsensitive_(isInsensitive) {}

    const char *toStr() { return reinterpret_cast<const char *>(word_); }

    const char *operator++();
    const char *operator*() { return this->toStr(); }

    bool operator!=(const Iterator &) const;
    bool operator==(const Iterator &) const;

    const char *parseWord();

   private:
    bool isLetter();
    bool isLower();
    char toLower();

    const char *pos_;
    const char *startPos_;
    bool isInsensitive_;

    size_t wsz_ = 0;
    char word_[wordMaxSize];

    bool isFinished_ = false;
  };

  Iterator begin() const;
  Iterator end() const;

 protected:
  const char *str_;
  const size_t sz_;
  bool isInsensitive_;
};

}  // namespace freqdict
