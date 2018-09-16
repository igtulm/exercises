package main

// #cgo CFLAGS: -Ic_binsearch
// #cgo LDFLAGS: -Lbin -lc_binsearch
// #include <c_binsearch/c_binsearch.h>
import "C"

import "fmt"
import "unsafe"

const N = 100

var sortedNums = make([]int32, N)

func init() {
	for i := 0; i < N; i++ {
		sortedNums[i] = int32(i)
	}
}

func binSearchRecur(dataSlice []int32, num int32, offset int32) int32 {
	sliceLen := int32(len(dataSlice))

	if sliceLen == 0 {
		return -1
	}

	mid := int32(sliceLen / 2)

	if dataSlice[mid] == num {
		return offset + mid
	}

	if num < dataSlice[mid] {
		nextSlice := dataSlice[0:mid]

		return binSearchRecur(nextSlice, num, offset)
	}

	if num > dataSlice[mid] {
		nextSlice := dataSlice[mid+1 : sliceLen]

		return binSearchRecur(nextSlice, num, offset+mid+1)
	}

	return -1
}

func binSearchSlice(dataSlice []int32, num int32) int32 {
	sliceLen := int32(len(dataSlice))
	if sliceLen == 0 {
		return -1
	}

	offset := int32(0)
	for {
		sliceLen = int32(len(dataSlice))
		mid := int32(sliceLen / 2)

		if sliceLen == 0 {
			break
		}

		if dataSlice[mid] == num {
			return offset + mid
		}

		if num < dataSlice[mid] {
			dataSlice = dataSlice[:mid]
			continue
		}

		if num > dataSlice[mid] {
			dataSlice = dataSlice[mid+1:]
			offset += mid + 1
		}
	}

	return -1
}

func binSearchMiddleCalc(dataSlice []int32, num int32) int32 {
	sliceLen := int32(len(dataSlice))
	if sliceLen == 0 {
		return -1
	}

	high := sliceLen
	low := int32(0)
	for {
		mid := int32((high - low) / 2)
		if num == dataSlice[low+mid] {
			return low + mid
		} else if low >= high {
			break
		} else if num < dataSlice[low+mid] {
			high = low + mid
		} else if num > dataSlice[low+mid] {
			low = low + mid + 1
		}
	}

	return -1
}

func binSearchMiddleCalcFromC(dataSlice []int32, num int32) int32 {
	sliceLen := len(dataSlice)
	if sliceLen == 0 {
		return -1
	}

	f := C.binsearch_middle_calc((*C.int)(unsafe.Pointer(&dataSlice[0])), C.ulong(sliceLen), C.int(num))

	return int32(f)
}

func main() {
	var requestedNum int32

	requestedNum = 47

	resRecur := binSearchRecur(sortedNums, requestedNum, 0)
	resSlice := binSearchSlice(sortedNums, requestedNum)
	resMiddleCalc := binSearchMiddleCalc(sortedNums, requestedNum)
	resMiddleCalcFromC := binSearchMiddleCalcFromC(sortedNums, requestedNum)

	fmt.Printf("result: %d %d %d %d\r\n", resRecur, resSlice, resMiddleCalc, resMiddleCalcFromC)
}
