```
Run on (8 X 2900 MHz CPU s)
CPU Caches:
  L1 Data 32K (x4)
  L1 Instruction 32K (x4)
  L2 Unified 262K (x4)
  L3 Unified 8388K (x1)
Load Average: 1.29, 2.30, 2.10
------------------------------------------------------------------------
Benchmark                             Time             CPU   Iterations
------------------------------------------------------------------------
BM_TrieCharNoderAllocate           14.4 ns         14.4 ns     42872980
BM_TrieUmapAllocate                57.2 ns         57.0 ns     13073849
BM_TrieMapAllocate                 43.0 ns         43.0 ns     15251342
BM_TrieHashMapAllocate             44.7 ns         44.6 ns     15417517
BM_TrieCharNoderInsert             1068 ns         1067 ns       674095
BM_TrieUmapInsert                  1090 ns         1088 ns       661413
BM_TrieMapInsert                   1108 ns         1105 ns       647082
BM_HashMapInsert                    475 ns          474 ns      1473421
BM_TrieCharNoderLookByPrefix        444 ns          442 ns      1619579
BM_TrieUmapLookByPrefix             427 ns          426 ns      1592726
BM_TrieMapLookByPrefix              420 ns          420 ns      1693038
BM_TrieCharNoderGetFreq            1024 ns         1023 ns       674764
BM_TrieUmapGetFreq                 1015 ns         1014 ns       667289
BM_TrieMapGetFreq                  1052 ns         1052 ns       702522
BM_HashMapGetFreq                   314 ns          314 ns      2261311
```
