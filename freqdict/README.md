Run on (8 X 2900 MHz CPU s)
CPU Caches:
  L1 Data 32K (x4)
  L1 Instruction 32K (x4)
  L2 Unified 262K (x4)
  L3 Unified 8388K (x1)
Load Average: 1.10, 1.33, 1.39
------------------------------------------------------------------------
Benchmark                             Time             CPU   Iterations
------------------------------------------------------------------------
BM_TrieCharNoderAllocate           14.4 ns         14.3 ns     45532601
BM_TrieUmapAllocate                52.9 ns         52.8 ns     13257074
BM_TrieMapAllocate                 48.6 ns         48.5 ns     13950059
BM_TrieCharNoderInsert             1058 ns         1057 ns       659600
BM_TrieUmapInsert                  1039 ns         1039 ns       649935
BM_TrieMapInsert                   1038 ns         1038 ns       666438
BM_TrieCharNoderLookByPrefix        425 ns          424 ns      1648409
BM_TrieUmapLookByPrefix             409 ns          408 ns      1753612
BM_TrieMapLookByPrefix              440 ns          439 ns      1697579
BM_TrieCharNoderGetFreq            1176 ns         1174 ns       594833
BM_TrieUmapGetFreq                 1160 ns         1158 ns       605777
BM_TrieMapGetFreq                  1147 ns         1145 ns       604506
