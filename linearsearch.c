//Write a C program to implement linear search for an integer array.
#include <stdio.h>
int linearSearch(int arr[], int s, int target) {
    for (int i = 0; i < s; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}
int main() {
    int arr[50];int s,target;
    printf("enter the size of the array");
    scanf("%d",&s);
    printf("enter the elements of the array");
    for(int i=0;i<s;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("enter element to be searched");
    scanf("%d",&target);
    int result = linearSearch(arr, s, target);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }
    return 0;
}