#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {
    int temp[50], i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= high) temp[k++] = arr[j++];
    for (i = low; i <= high; i++) arr[i] = temp[i];
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[50], n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    mergeSort(arr, 0, n - 1);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}
