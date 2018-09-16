#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// OS X
#ifdef __MACH__
#include <mach/clock.h>
#include <mach/mach.h>
#endif

#include "c_binsearch.h"

static void gettime(struct timespec *ts)
{
// OS X
#ifdef __MACH__
    clock_serv_t cclock;
    mach_timespec_t mts;
    host_get_clock_service(mach_host_self(), REALTIME_CLOCK, &cclock);
    clock_get_time(cclock, &mts);
    mach_port_deallocate(mach_task_self(), cclock);
    ts->tv_sec = mts.tv_sec;
    ts->tv_nsec = mts.tv_nsec;
#else
    clock_gettime(CLOCK_MONOTONIC, ts);
#endif
}

int main()
{
    size_t arr_size = 1000000;

    int arr[arr_size];

    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = i;
    }

    int iter_count = 1000000;
    struct timespec begin_ts, end_ts;

    gettime(&begin_ts);
    for (int i = 0; i < iter_count; i++)
    {
        int num = i % arr_size;
        int res = binsearch_middle_calc(arr, arr_size, num);
        if (res != num)
        {
            printf("Expected %d, got %d \r\n", num, res);
            exit(1);
        }
    }
    gettime(&end_ts);

    double elapsed_time = difftime(end_ts.tv_sec, begin_ts.tv_sec) * 1e9 +
                          difftime(end_ts.tv_nsec, begin_ts.tv_nsec);

    printf("binary search: %d iterations, elapsed time: %u ns, iteration time: "
           "%f ns\n",
           iter_count, (unsigned)elapsed_time, elapsed_time / iter_count);

    return 0;
}
