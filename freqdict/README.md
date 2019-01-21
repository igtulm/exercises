```
Run on (8 X 2900 MHz CPU s)
CPU Caches:
  L1 Data 32K (x4)
  L1 Instruction 32K (x4)
  L2 Unified 262K (x4)
  L3 Unified 8388K (x1)
Load Average: 1.51, 1.49, 1.46
------------------------------------------------------------------------
Benchmark                             Time             CPU   Iterations
------------------------------------------------------------------------
BM_TrieCharNoderAllocate           13.5 ns         13.5 ns     45537341
BM_TrieUmapAllocate                51.5 ns         51.5 ns     13310515
BM_TrieMapAllocate                 42.0 ns         42.0 ns     16759683
BM_TrieCharNoderInsert              977 ns          976 ns       712330
BM_TrieUmapInsert                   981 ns          981 ns       708854
BM_TrieMapInsert                    978 ns          978 ns       713449
BM_HashMapInsert                    422 ns          422 ns      1622823
BM_TrieCharNoderLookByPrefix        362 ns          362 ns      1773683
BM_TrieUmapLookByPrefix             406 ns          406 ns      1950768
BM_TrieMapLookByPrefix              362 ns          362 ns      1881114
BM_TrieCharNoderGetFreq             980 ns          980 ns       717118
BM_TrieUmapGetFreq                  975 ns          974 ns       668551
BM_TrieMapGetFreq                   972 ns          972 ns       712838
BM_HashMapGetFreq                   297 ns          297 ns      2307581
```
