#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* vanEck (int n);

void printArray(int* arr, int size) {
	printf("[");
	for (int i = 0; i < size; i++) {
		printf("%d", arr[i]);
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main () {
	int* test = vanEck(50);
	int expected[] = {0, 0, 1, 0, 2, 0, 2, 2, 1, 6, 0, 5, 0, 2, 6, 5, 4, 0, 5, 3, 0, 3, 2, 9, 0, 4, 9, 3, 6, 14, 0, 6, 3, 5, 15, 0, 5, 3, 5, 2, 17, 0, 6, 11, 0, 3, 8, 0, 3, 3};
    if (!memcmp(expected, test, 50*sizeof(int))) {
        printf("Passed!\n");
    } else {
        printf("Failed!\nExpected : ");
       	printArray(expected, 50);
       	printf("But I got : ");
		printArray(test, 50);
    }
	
}
