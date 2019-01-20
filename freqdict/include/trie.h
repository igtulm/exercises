#pragma once

#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include "charnoder.h"

namespace freqdict {

using std::string;
using std::vector;

class Trie {
 public:
  Trie() {}
  Trie(char* s) { insert(s); }
  Trie(string s) { insert(&s[0]); }
  ~Trie() {}

  void Insert(char* s) { insert(s); }
  void Insert(string s) { insert(&s[0]); }
  bool IsPresented(char* s) { return isPresented(s); }
  bool IsPresented(string s) { return isPresented(&s[0]); }
  vector<string> LookByPrefix(char* s) { return lookByPrefix(s); }
  vector<string> LookByPrefix(string s) { return lookByPrefix(&s[0]); }
  unsigned GetFreq(char* s) { return getFreq(s); }
  unsigned GetFreq(string s) { return getFreq(&s[0]); }

 protected:
  CharNoder<Trie*> charsToNodes_;
  unsigned freq_ = 0;

  void insert(char* s);

  bool isPresented(char* s) { return getNodeByPrefix(s) != nullptr; }
  Trie* getNodeByPrefix(char* s);
  void getWordsByPrefix(char* prefix, vector<string>* res);

  vector<string> lookByPrefix(char* s);
  unsigned getFreq(char* s);
};

void Trie::insert(char* s) {
  Trie* tr = this;
  for (char* p = s; *p; ++p) {
    if (tr->charsToNodes_.find(*p) == tr->charsToNodes_.end()) {
      tr->charsToNodes_[*p] = new Trie();
    }
    tr = tr->charsToNodes_[*p];
  }
  tr->freq_++;
}

Trie* Trie::getNodeByPrefix(char* s) {
  Trie* tr = this;
  for (char* p = s; *p; ++p) {
    auto tst = tr->charsToNodes_.find(*p);
    if (tst == tr->charsToNodes_.end()) {
      return nullptr;
    }
    tr = tr->charsToNodes_[*p];
  }
  return tr;
}

void Trie::getWordsByPrefix(char* prefix, vector<string>* res) {
  if (freq_ > 0) {
    res->push_back(prefix);
  }

  for (auto cn : charsToNodes_) {
    if (cn.second == nullptr) {
      continue;
    }
    string str(prefix);
    char c = cn.first;
    str.push_back(c);
    cn.second->getWordsByPrefix(&str[0], res);
  }
}

vector<string> Trie::lookByPrefix(char* s) {
  vector<string> res;

  if (!*s) {
    getWordsByPrefix(s, &res);
    return res;
  }

  Trie* trPtr = getNodeByPrefix(s);
  if (trPtr == nullptr) {
    return res;
  }

  trPtr->getWordsByPrefix(s, &res);
  return res;
}

unsigned Trie::getFreq(char* s) {
  Trie* trPtr = getNodeByPrefix(s);
  if (trPtr == nullptr) {
    return 0;
  }
  return trPtr->freq_;
}

template <template <typename...> class TStorageType>
class TrieMap : public Trie {
 protected:
  using TStorageMap = TStorageType<char, TrieMap*>;
  using TStorage = TStorageMap;
  TStorage charsToNodes_;
};

using TrieOnMap = TrieMap<std::map>;
using TrieOnUMap = TrieMap<std::unordered_map>;
using TrieOnCn = Trie;

}  // namespace freqdict
