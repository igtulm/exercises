package main

import (
	"testing"
)

func Benchmark(b *testing.B) {
	data := make([]int32, 1000000)
	v := 0
	for i := 0; i < len(data); i++ {
		data[i] = int32(v)
		v += 10
	}
	b.Run("binary search recursive", func(b *testing.B) {
		b.ReportAllocs()
		for i := 0; i < b.N; i++ {
			binSearchRecur(data, int32(i%len(data)), 0)
		}
	})
	b.Run("binary search slice", func(b *testing.B) {
		b.ReportAllocs()
		for i := 0; i < b.N; i++ {
			binSearchSlice(data, int32(i%len(data)))
		}
	})
	b.Run("binary search middle calculate", func(b *testing.B) {
		b.ReportAllocs()
		for i := 0; i < b.N; i++ {
			binSearchMiddleCalc(data, int32(i%len(data)))
		}
	})
	b.Run("binary search C", func(b *testing.B) {
		b.ReportAllocs()
		for i := 0; i < b.N; i++ {
			binSearchMiddleCalcFromC(data, int32(i%len(data)))
		}
	})
}
