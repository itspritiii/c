//Write a C program to implement linear probing for collision resolution in hashing.
#include<stdio.h>
#define SIZE 10
int hashTable[SIZE];
void insert(int key) {
    int index = key % SIZE;
    while (hashTable[index] != 0) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}
int search(int key) {
    int index = key % SIZE;
    while (hashTable[index] != 0) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % SIZE;
    }
    return -1;
}
int main() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = 0;
    }
    printf("enter no. of elements to be inserted");
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("enter element %d: ",i+1);
        int element;
        scanf("%d",&element);
        insert(element);
    }
printf("enter element to be searched");
    int target;
    scanf("%d",&target);
    int result = search(target);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
