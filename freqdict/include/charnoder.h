#pragma once

#include <array>
#include <bitset>
#include <iostream>
#include <stdexcept>

namespace freqdict {

using std::array;
using std::bitset;
using std::out_of_range;

const int alphaCharsCount = 'Z' - 'A' + 1;
const int allAlphaCharsCount = 2 * alphaCharsCount;

template <typename T, size_t N = allAlphaCharsCount>
class CharNoder {
 public:
  typedef array<T, N> Nodes;
  typedef bitset<N> Status;

  CharNoder() {}
  ~CharNoder() {}

  class ReaderWriter {
   public:
    ReaderWriter(CharNoder& cn, char c);

    operator T() {
      if (!cn_.status_.test(index_)) {
        const T defaultValue = {0};
        return defaultValue;
      }
      return cn_.nodes_[index_];
    }

    T& operator=(const T& other) {
      cn_.status_.set(index_, true);
      return cn_.nodes_[index_] = other;
    }

   protected:
    CharNoder& cn_;
    int index_;
  };

  ReaderWriter operator[](char c) { return ReaderWriter(*this, c); }

  class Iterator {
   public:
    Iterator(CharNoder& cn, char c);

    Iterator& operator*() { return *this; }

    Iterator& operator++();

    bool operator!=(const Iterator& other) const {
      return first != other.first || second != other.second;
    }
    bool operator==(const Iterator& other) const {
      return first == other.first && second == other.second;
    }

    bool IsFinished() { return first == '\0'; }

    char first;
    T& second;

   protected:
    CharNoder& cn_;

    void finish() { first = '\0'; }
  };

  Iterator begin();
  Iterator end();
  Iterator find(char c);

 protected:
  Nodes nodes_;
  Status status_ = {0};
};

static int charToIndex(char c) {
  if (!isalpha(c)) {
    return -1;
  }
  return isupper(c) ? c - 'A' : c - 'a' + alphaCharsCount;
}

static char indexToChar(int index) {
  if (index < 0 || index >= allAlphaCharsCount) {
    return '\0';
  }
  if (index >= 0 && index < alphaCharsCount) {
    return static_cast<char>(index + 'A');
  }
  return static_cast<char>(index - alphaCharsCount + 'a');
}

template <typename T, size_t N>
typename CharNoder<T, N>::Iterator CharNoder<T, N>::begin() {
  return Iterator(*this, indexToChar(0));
}

template <typename T, size_t N>
typename CharNoder<T, N>::Iterator CharNoder<T, N>::end() {
  return Iterator(*this, '\0');
}

template <typename T, size_t N>
typename CharNoder<T, N>::Iterator CharNoder<T, N>::find(char c) {
  return Iterator(*this, c);
}

template <typename T, size_t N>
CharNoder<T, N>::ReaderWriter::ReaderWriter(CharNoder& cn, char c) : cn_(cn) {
  index_ = charToIndex(c);
  if (index_ < 0) {
    throw out_of_range("Index is out of range");
  }
}

template <typename T, size_t N>
CharNoder<T, N>::Iterator::Iterator(CharNoder<T, N>& cn, char c)
    : cn_(cn), first(c), second(cn.nodes_[0]) {
  int index = charToIndex(first);
  if (index == -1 || !cn_.status_.test(index)) {
    finish();
    return;
  }
  second = cn_[first];
}

template <typename T, size_t N>
typename CharNoder<T, N>::Iterator& CharNoder<T, N>::Iterator::operator++() {
  int index = charToIndex(first);
  if (index > -1) {
    ++index;
  }

  first = indexToChar(index);
  index = charToIndex(first);

  if (index > -1) {
    second = cn_[first];
  }
  return *this;
}

}  // namespace freqdict
