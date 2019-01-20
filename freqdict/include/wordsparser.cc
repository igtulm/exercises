#include "wordsparser.h"

namespace freqdict {

WordsParser::Iterator WordsParser::begin() const {
  WordsParser::Iterator it(str_, isInsensitive_);
  it.parseWord();
  return it;
};

WordsParser::Iterator WordsParser::end() const {
  return WordsParser::Iterator(str_, str_ + sz_, isInsensitive_);
};

bool WordsParser::Iterator::isLower() { return *pos_ >= 'a' && *pos_ <= 'z'; }

bool WordsParser::Iterator::isLetter() {
  return (*pos_ >= 'A' && *pos_ <= 'Z') || isLower();
}

char WordsParser::Iterator::toLower() {
  return isLetter() ? isLower() ? *pos_ : *pos_ - 'A' + 'a' : *pos_;
}

const char *WordsParser::Iterator::operator++() { return this->parseWord(); }

bool WordsParser::Iterator::operator!=(
    const WordsParser::Iterator &other) const {
  return pos_ != other.pos_;
}

bool WordsParser::Iterator::operator==(
    const WordsParser::Iterator &other) const {
  return pos_ == other.pos_;
}

const char *WordsParser::Iterator::parseWord() {
  if (isFinished_) {
    word_[0] = '\0';

    if (*pos_) {
      ++pos_;
    }
  }

  bool isGrabbing = false;

  while (*pos_) {
    if (!isGrabbing && isLetter()) {
      isGrabbing = true;
      startPos_ = pos_;
    }

    if (isGrabbing) {
      if (!isLetter()) {
        wsz_ = static_cast<size_t>(pos_ - startPos_);
        assert(wsz_ < wordMaxSize);
        word_[wsz_] = '\0';
        break;
      }

      word_[pos_ - startPos_] = isInsensitive_ ? toLower() : *pos_;

      if (!*(pos_ + 1)) {
        wsz_ = static_cast<size_t>(pos_ - startPos_);
        assert(wsz_ + 1 < wordMaxSize);
        word_[wsz_ + 1] = '\0';
        isFinished_ = true;
        break;
      }
    }

    ++pos_;
  }

  return reinterpret_cast<const char *>(word_);
}

}  // namespace freqdict
