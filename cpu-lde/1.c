/**
 * OSTEP Chapter 6 Homework
 *
 * Measure the costs of a system call.
 */

#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void measure_read(int iterations)
{
    long sum = 0;
    struct timeval time1;
    struct timeval time2;

    int fd = 0;
    long diff;
    char buf[1];
    for (int i = 0; i < iterations; ++i) {
       gettimeofday(&time1, NULL);
       read(fd, buf, 0);
       gettimeofday(&time2, NULL);
       diff = time2.tv_usec - time1.tv_usec;
       printf("Call length: %ld\n", diff);
       sum += diff;
    }
    printf("Average through %d iterations: %ld\n", iterations, sum / iterations);
}

int main(int argc, char *argv[])
{
    measure_read(atoi(argv[1]));
    return 0;
}
