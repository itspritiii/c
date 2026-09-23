//Write a C program to implement recursive user defined function to implement Binary Search for an integer array.
#include <stdio.h>
int binarySearch(int arr[], int low, int high, int target) {
    if (low > high) {
        return -1;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] > target) {
        return binarySearch(arr, low, mid - 1, target);
    } else {
        return binarySearch(arr, mid + 1, high, target);
    }
}
int main() {
    int arr[50];int s,target;
    printf("enter the size of the array");
    scanf("%d",&s);
    printf("enter the elements of the sorted array");
    for(int i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter the element to be searched");
    scanf("%d",&target);
    int result = binarySearch(arr, 0, s - 1, target);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    return 0;
}