## Go/C/Cgo exercise.

Binary search benchmarking.

int32 type is used for c-go compatibility.

```
Benchmark from C:
binary search: 1000000 iterations, elapsed time: 67477261 ns, iteration time: 67.477261 ns
Benchmark from Go:
goos: darwin
goarch: amd64
Benchmark/binary_search_recursive-8         	20000000	        84.5 ns/op	       0 B/op	       0 allocs/op
Benchmark/binary_search_slice-8             	20000000	        58.5 ns/op	       0 B/op	       0 allocs/op
Benchmark/binary_search_middle_calculate-8  	20000000	        59.6 ns/op	       0 B/op	       0 allocs/op
Benchmark/binary_search_C-8                 	20000000	        87.4 ns/op	       0 B/op	       0 allocs/op
PASS
ok  	_/Users/tulm/Projects/exercises/bin_search	6.120s
```
