#include <benchmark/benchmark.h>
#include <string>
#include <vector>
#include "hashmap.h"
#include "trie.h"

using std::string;
using std::vector;

static vector<string> twords = {
    "analysis",
    "approval",
    "assessment",
    "attempt",
    "check",
    "evaluation",
    "experiment",
    "final",
    "inquiry",
    "inspection",
    "investigation",
    "search",
    "standard",
    "trial",
    "catechism",
    "comp",
    "confirmation",
    "corroboration",
    "countdown",
    "criterion",
    "elimination",
    "essay",
    "exam",
    "fling",
    "go",
    "inquest",
    "lick",
    "oral",
    "ordeal",
    "preliminary",
    "probation",
    "probing",
    "proof",
    "questionnaire",
    "scrutiny",
    "shibboleth",
    "substantiation",
    "touchstone",
    "try",
    "tryout",
    "verification",
    "yardstick",
    "trial",
    "and",
    "error",
};

////
//// Alloc bench
////

static void BM_TrieCharNoderAllocate(benchmark::State &state) {
  for (auto _ : state) {
    freqdict::TrieOnCn tr;
  }
}
BENCHMARK(BM_TrieCharNoderAllocate);

static void BM_TrieUmapAllocate(benchmark::State &state) {
  for (auto _ : state) {
    freqdict::TrieOnUMap tr;
  }
}
BENCHMARK(BM_TrieUmapAllocate);

static void BM_TrieMapAllocate(benchmark::State &state) {
  for (auto _ : state) {
    freqdict::TrieOnMap tr;
  }
}
BENCHMARK(BM_TrieMapAllocate);

static void BM_TrieHashMapAllocate(benchmark::State &state) {
  for (auto _ : state) {
    freqdict::HashMap hm;
  }
}
BENCHMARK(BM_TrieHashMapAllocate);

////
//// Insert bench
////

static void BM_TrieCharNoderInsert(benchmark::State &state) {
  freqdict::TrieOnCn tr;

  unsigned i = 0;
  for (auto _ : state) {
    tr.Insert(twords[i]);
    ++i;
    if (i == twords.size()) i = 0;
  }
}
BENCHMARK(BM_TrieCharNoderInsert);

static void BM_TrieUmapInsert(benchmark::State &state) {
  freqdict::TrieOnUMap tr;

  unsigned i = 0;
  for (auto _ : state) {
    tr.Insert(twords[i]);
    ++i;
    if (i == twords.size()) i = 0;
  }
}
BENCHMARK(BM_TrieUmapInsert);

static void BM_TrieMapInsert(benchmark::State &state) {
  freqdict::TrieOnMap tr;

  unsigned i = 0;
  for (auto _ : state) {
    tr.Insert(twords[i]);
    ++i;
    if (i == twords.size()) i = 0;
  }
}
BENCHMARK(BM_TrieMapInsert);

static void BM_HashMapInsert(benchmark::State &state) {
  freqdict::HashMap hm;

  unsigned i = 0;
  for (auto _ : state) {
    hm.Insert(twords[i]);
    ++i;
    if (i == twords.size()) i = 0;
  }
}
BENCHMARK(BM_HashMapInsert);

////
//// LookByPrefix bench
////

static void BM_TrieCharNoderLookByPrefix(benchmark::State &state) {
  freqdict::TrieOnCn tr;

  // seeding
  for (auto &v : twords) tr.Insert(v);

  unsigned i = 0;
  for (auto _ : state) {
    tr.LookByPrefix(twords[i].substr(0, 2));
    ++i;
    if (i == twords.size()) i = 0;
  }
}
BENCHMARK(BM_TrieCharNoderLookByPrefix);

static void BM_TrieUmapLookByPrefix(benchmark::State &state) {
  freqdict::TrieOnUMap tr;

  // seeding
  for (auto &v : twords) tr.Insert(v);

  unsigned i = 0;
  for (auto _ : state) {
    tr.LookByPrefix(twords[i].substr(0, 2));
    ++i;
    if (i == twords.size()) i = 0;
  }
}
BENCHMARK(BM_TrieUmapLookByPrefix);

static void BM_TrieMapLookByPrefix(benchmark::State &state) {
  freqdict::TrieOnMap tr;

  // seeding
  for (auto &v : twords) tr.Insert(v);

  unsigned i = 0;
  for (auto _ : state) {
    tr.LookByPrefix(twords[i].substr(0, 2));
    ++i;
    if (i == twords.size()) i = 0;
  }
}
BENCHMARK(BM_TrieMapLookByPrefix);

////
//// GetFreq bench
////

static void BM_TrieCharNoderGetFreq(benchmark::State &state) {
  freqdict::TrieOnCn tr;

  // seeding
  for (auto &v : twords) tr.Insert(v);

  unsigned i = 0;
  for (auto _ : state) {
    tr.GetFreq(twords[i]);
    ++i;
    if (i == twords.size()) i = 0;
  }
}
BENCHMARK(BM_TrieCharNoderGetFreq);

static void BM_TrieUmapGetFreq(benchmark::State &state) {
  freqdict::TrieOnUMap tr;

  // seeding
  for (auto &v : twords) tr.Insert(v);

  unsigned i = 0;
  for (auto _ : state) {
    tr.GetFreq(twords[i]);
    ++i;
    if (i == twords.size()) i = 0;
  }
}
BENCHMARK(BM_TrieUmapGetFreq);

static void BM_TrieMapGetFreq(benchmark::State &state) {
  freqdict::TrieOnMap tr;

  // seeding
  for (auto &v : twords) tr.Insert(v);

  unsigned i = 0;
  for (auto _ : state) {
    tr.GetFreq(twords[i]);
    ++i;
    if (i == twords.size()) i = 0;
  }
}
BENCHMARK(BM_TrieMapGetFreq);

static void BM_HashMapGetFreq(benchmark::State &state) {
  freqdict::HashMap hm;

  // seeding
  for (auto &v : twords) hm.Insert(v);

  unsigned i = 0;
  for (auto _ : state) {
    hm.GetFreq(twords[i]);
    ++i;
    if (i == twords.size()) i = 0;
  }
}
BENCHMARK(BM_HashMapGetFreq);

///
/// \brief BENCHMARK_MAIN
///
BENCHMARK_MAIN();
