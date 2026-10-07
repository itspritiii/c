//Write C program to implement sorting of your choice (at least three variants) on a 2D integer array such that each row sort in alternative ways (ascending order and descending order). Print the following details at the end:
//1. Total number of iterations per algorithm (for complete sorting form random sequence)
//2. Total Time taken for complete sorting as per a for mentioned way.
//3. Total number of swapping happened for complete sorting (if applicable, otherwise print NA)
/*ex-1  2   3  4 
     8  7   6  5
     9 10 11 12 */ 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble_sort(int arr[], int n, int *iterations, int *swaps) {
    clock_t start, end;
    start = clock();
    for (int i = 0; i < n - 1; i++) {
        (*iterations)++;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;
            }
        }
    }
    end = clock();
    printf("Time taken for bubble sort: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}
void selection_sort(int arr[], int n, int *iterations, int *swaps) {
    clock_t start, end;
    start = clock();
    for (int i = 0; i < n - 1; i++) {
        (*iterations)++;
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            (*swaps)++;
        }
    }
    end = clock();
    printf("Time taken for selection sort: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
}
 void heapify(int arr[], int n, int i, int *iterations, int *swaps) {
    (*iterations)++;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        (*swaps)++;
        heapify(arr, n, largest, iterations, swaps);
    }
    void heapp_sort(int arr[], int n, int *iterations, int *swaps) {
        clock_t start, end;
        start = clock();
        for(i=n/2-1;i>=0;i--){
            heapify(arr,n,i,iterations,swaps);
        }
        for(i=n-1;i>0;i--){
            int temp=arr[0];
            arr[0]=arr[i];
            arr[i]=temp;
            (*swaps)++;
            heapify(arr,i,0,iterations,swaps);
        }
        end = clock();
        printf("Time taken for heap sort: %f seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    }
    }
int main()
{
int arr[100][100],rows,cols,choice;
printf("Enter the number of rows and columns in the 2D array: ");
scanf("%d %d", &rows, &cols);
printf("Enter the elements of the 2D array: \n");
for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
        scanf("%d", &arr[i][j]);
    }
}
printf("Choose a sorting algorithm:\n");
printf("1. Bubble Sort\n");
printf("2. Selection Sort\n");
printf("3. Heap Sort\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch(choice){
    case 1:
        for(int i=0;i<rows;i++){
            int iterations=0,swaps=0;
            if(i%2==0){
                bubble_sort(arr[i],cols,&iterations,&swaps);
            }
            else{
                bubble_sort(arr[i],cols,&iterations,&swaps);
            }
            printf("Row %d: Total iterations: %d, Total swaps: %d\n", i+1, iterations, swaps);
        }
        break;
    case 2:
        for(int i=0;i<rows;i++){
            int iterations=0,swaps=0;
            if(i%2==0){
                selection_sort(arr[i],cols,&iterations,&swaps);
            }
            else{
                selection_sort(arr[i],cols,&iterations,&swaps);
            }
            printf("Row %d: Total iterations: %d, Total swaps: %d\n", i+1, iterations, swaps);
        }
        break;
    case 3:
        for(int i=0;i<rows;i++){
            int iterations=0,swaps=0;
            if(i%2==0){
                heapp_sort(arr[i],cols,&iterations,&swaps);
            }
            else{
                heapp_sort(arr[i],cols,&iterations,&swaps);
            }
            printf("Row %d: Total iterations: %d, Total swaps: %d\n", i+1, iterations, swaps);
        }
        break;
    default:
        printf("Invalid choice!\n");
}
}