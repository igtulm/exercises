#include "c_binsearch.h"

int binsearch_middle_calc(int *arr, size_t size, int num)
{
  if (size == 0)
  {
    return -1;
  }

  int high = size;
  int low = 0;
  int mid;

  while (low < high)
  {
    mid = (high - low) / 2;

    if (num == arr[low + mid])
    {
      return low + mid;
    }
    else if (num < arr[low + mid])
    {
      high = low + mid;
    }
    else if (num > arr[low + mid])
    {
      low = low + mid + 1;
    }
  }

  return -1;
}
