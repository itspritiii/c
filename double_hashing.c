//Write a C program to implement Double Hashing technique to mitigate collision in hashing.
#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10
#define EMPTY 0
#define DELETED -1
int hash1(int key) {
    return key % TABLE_SIZE;
}
int hash2(int key) {
    return 7 - (key % 7);
}
int double_hash(int key, int i) {
    return (hash1(key) + i * hash2(key)) % TABLE_SIZE;
}
int search(int table[], int key) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        int index = double_hash(key, i);
        if (table[index] == key) {
            return index;
        }
        if (table[index] == EMPTY) {
            return -1;
        }
    }
    return -1;
}
void insert(int table[], int key) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        int index = double_hash(key, i);
        if (table[index] == EMPTY || table[index] == DELETED) {
            table[index] = key;
            return;
        }
    }
    printf("Hash table is full\n");
}
void delete(int table[], int key) {
    int index = search(table, key);
    if (index != -1) {
        table[index] = DELETED;
    } else {
        printf("Key not found\n");
    }
}
int main() {
    int table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = EMPTY;
    }

    insert(table, 15);
    insert(table, 25);
    insert(table, 35);

    printf("Search for 25: %d\n", search(table, 25));
    printf("Search for 45: %d\n", search(table, 45));

    delete(table, 25);
    printf("Search for 25 after deletion: %d\n", search(table, 25));

    return 0;
}