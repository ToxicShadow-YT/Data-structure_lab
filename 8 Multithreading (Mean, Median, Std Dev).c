#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

double mean, median, stddev;
int *arr, n;

void *calc_mean(void *arg) {
    double sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    mean = sum / n;
    pthread_exit(0);
}

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void *calc_median(void *arg) {
    qsort(arr, n, sizeof(int), cmp);
    if(n % 2 == 0)
        median = (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        median = arr[n/2];
    pthread_exit(0);
}

void *calc_stddev(void *arg) {
    double sum = 0;
    for(int i = 0; i < n; i++)
        sum += pow(arr[i] - mean, 2);
    stddev = sqrt(sum / n);
    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    n = argc - 1;
    arr = malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
        arr[i] = atoi(argv[i+1]);

    pthread_t t1, t2, t3;

    pthread_create(&t1, NULL, calc_mean, NULL);
    pthread_create(&t2, NULL, calc_median, NULL);

    pthread_join(t1, NULL);
    pthread_create(&t3, NULL, calc_stddev, NULL);

    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    printf("Mean = %.2f\nMedian = %.2f\nStd Dev = %.2f\n", mean, median, stddev);

    free(arr);
    return 0;
}
