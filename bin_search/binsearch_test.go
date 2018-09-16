package main

import (
	"fmt"
	"testing"
)

const testN = 100

var testArr = make([]int32, testN)
var testValues = []int32{0, 1, 3, 4, 5, 22, 10, 48, 50, 63, 79, 99}

func init() {
	for i := 0; i < testN; i++ {
		testArr[i] = int32(i)
	}
}

func TestBinSearchRecur(t *testing.T) {
	for _, v := range testValues {
		res := binSearchRecur(testArr, v, 0)

		if res != v {
			err := fmt.Errorf("Expected index %d, got %d", v, res)
			t.Error(err)
			break
		}
	}
}
func TestBinSearchSlice(t *testing.T) {
	for _, v := range testValues {
		res := binSearchSlice(testArr, v)

		if res != v {
			err := fmt.Errorf("Expected index %d, got %d", v, res)
			t.Error(err)
			break
		}
	}
}

func TestMiddleCalc(t *testing.T) {
	for _, v := range testValues {
		res := binSearchMiddleCalc(testArr, v)

		if res != v {
			err := fmt.Errorf("Expected index %d, got %d", v, res)
			t.Error(err)
			break
		}
	}
}

func TestMiddleCalcFromC(t *testing.T) {
	for _, v := range testValues {
		res := binSearchMiddleCalcFromC(testArr, v)

		if res != v {
			err := fmt.Errorf("Expected index %d, got %d", v, res)
			t.Error(err)
			break
		}
	}
}
