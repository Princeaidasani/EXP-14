#include <stdio.h>

// Function prototypes
void mergeSort(int arr[], int l, int r);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void merge(int arr[], int l, int m, int r);
void printArray(int arr[], int size);

int main() {
    int arr[100], n, choice;

    // Input: Number of elements and the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        // Menu options
        printf("\nMenu:\n");
        printf("1. Merge Sort\n");
        printf("2. Quick Sort\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Performing Merge Sort...\n");
                mergeSort(arr, 0, n - 1);
                printf("Sorted Array: ");
                printArray(arr, n);
                break;

            case 2:
                printf("Performing Quick Sort...\n");
                quickSort(arr, 0, n - 1);
                printf("Sorted Array: ");
                printArray(arr, n);
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to implement Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2; // Find the middle point
        mergeSort(arr, l, m);    // Sort the first half
        mergeSort(arr, m + 1, r); // Sort the second half
        merge(arr, l, m, r);     // Merge the two halves
    }
}

// Function to merge two halves
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Temporary arrays
    int L[n1], R[n2];

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partitioning index
        quickSort(arr, low, pi - 1); // Sort elements before partition
        quickSort(arr, pi + 1, high); // Sort elements after partition
    }
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Pivot
    int i = (low - 1);     // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; // Increment index of smaller element
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}