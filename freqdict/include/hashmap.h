#pragma once

#include <string>
#include <unordered_map>

namespace freqdict {

using std::pair;
using std::string;
using std::unordered_map;

class HashMap {
 public:
  void Insert(string s);
  bool IsPresented(string s) { return isPresented(s); }
  unsigned GetFreq(string s) { return isPresented(s) ? storage_[s] : 0; }

 protected:
  unordered_map<string, unsigned> storage_;

  bool isPresented(string s) { return storage_.find(s) != storage_.end(); }
};

void HashMap::Insert(string s) {
  if (storage_.find(s) == storage_.end()) {
    storage_[s] = 1;
    return;
  }

  unsigned freq = storage_[s];
  ++freq;
  storage_[s] = freq;
}

}  // namespace freqdict
