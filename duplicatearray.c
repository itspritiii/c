#include<stdio.h>
void remove_duplicates(int arr[], int n) {
    if (n == 0 || n == 1) {
        return;
    }
    int j = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n - 1];
    for (int i = j; i < n; i++) {
        arr[i] = 0;
    }
}   
int main() {
    int arr[100], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array (sorted order): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    remove_duplicates(arr, n);
    printf("Array after removing duplicates: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    return 0;
}
