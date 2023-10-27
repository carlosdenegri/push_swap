#include <stdio.h>
#include <stdlib.h>

// Data structure to store elements and their original indices
struct IndexedElement {
    int value;
    int originalIndex;
};

// Function to compare two IndexedElements for sorting
int compareIndexedElements(const void* a, const void* b) {
    return ((struct IndexedElement*)a)->value - ((struct IndexedElement*)b)->value;
}

int main() {
    int arr[] = {2000, 5, 2, 3, 99, 1001, 7, 2011};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create an array of IndexedElements to store values and their original indices
    struct IndexedElement indexedArr[n];
    for (int i = 0; i < n; i++) {
        indexedArr[i].value = arr[i];
        indexedArr[i].originalIndex = i;
    }

    // Sort the indexed array by values while maintaining original indices
    qsort(indexedArr, n, sizeof(struct IndexedElement), compareIndexedElements);

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Middle number: %d (original index: %d)\n", indexedArr[n / 2].value, indexedArr[n / 2].originalIndex);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("   %d ", indexedArr[i].value);
        printf("%d", indexedArr[i].originalIndex);
    }
    printf("\n");

    return 0;
}
