//Binary Search
#include<stdio.h>

struct Array {
    int A[10]; // Assuming a fixed-size array
    int length;
};

void Display(struct Array arr) {
    int i;
    printf("\nElements are:\n");
    for (i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);
}

int BinarySearch(struct Array arr, int key) {
    int l, mid, h;
    l = 0;
    h = arr.length - 1;
    while (l <= h) {
        mid = (l + h) / 2;
        if (key == arr.A[mid]) {
            return mid;
        } else if (key < arr.A[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}
//Using Recursion
int RBinSearch(int a[], int l, int h, int key) {
    int mid = 0;
    if (l <= h) {
        mid = (l + h) / 2;
        if (key == a[mid]) {
            return mid;
        } else if (key < a[mid]) {
            return RBinSearch(a, l, mid - 1, key);
        } else {
            return RBinSearch(a, mid + 1, h, key);
        }
    }
    return -1;
}

int main() {
    struct Array arr1 = {{2, 3, 9, 16, 18, 21, 28, 32, 35}, 9};
    Display(arr1);
    printf("\nFound at index: %d\n", BinarySearch(arr1, 16));
    return 0;
}
//The best case time complexity is O(1) and the worst case time complexity is O(log n).