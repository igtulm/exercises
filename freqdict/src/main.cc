#include <stdio.h>
#include "trie.h"

#include "hashmap.h"
#include "wordsparser.h"

using freqdict::Trie;
using freqdict::WordsParser;

int main() {
  WordsParser wp(
      "The time has the come, the walrus said, to talk of many things.", false);

  freqdict::TrieOnUMap trUmap;
  freqdict::TrieOnUMap trMap;
  freqdict::TrieOnCn trCn;
  freqdict::HashMap Hmap;
  for (auto word : wp) {
    trUmap.Insert(word);
    trMap.Insert(word);
    trCn.Insert(word);
    Hmap.Insert(word);
  }

  printf("Found: %i\n", trUmap.IsPresented("the"));
  printf("Freq: %u\n", trUmap.GetFreq("the"));

  printf("Found: %i\n", trMap.IsPresented("the"));
  printf("Freq: %u\n", trMap.GetFreq("the"));

  printf("Found: %i\n", trCn.IsPresented("the"));
  printf("Freq: %u\n", trCn.GetFreq("the"));

  printf("Found: %i\n", Hmap.IsPresented("the"));
  printf("Freq: %u\n", Hmap.GetFreq("the"));
}
