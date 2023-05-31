#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


//start = pointer to which stack's memory will be allocated
//end = points to first memory cell AFTER end of stack
//element at end of array at top of stack
    //element at end of array is at top of stack
    //pointed to by (end-1)

int isEmpty (const long *start, const long *end);
void push (long **start, long **end, long value);
long pop (long **start, long **end); // You don't have to implement this one.

//determines if stack is empty of not
//&start == &stop
//*start/stop is null
int isEmpty (const long *start, const long *end) {
    if ((start==end) || (start==NULL) || (end==NULL)) {
        return 1;
    }
    else {
        return 0;
    }
}

//long *stack;
void push (long **start, long **end, long value) {
    static long *stack;
    //if ((start==NULL) || (end==NULL)) {
    if (isEmpty(*start,*end) == 1){
        //printf("p: %p", start);
        stack = (long*)malloc(sizeof(long));
        //assigning value to pointer
        *stack = value;
        //giving first address of stack
        *start = stack;
        *end = stack+1;
    }

    //printf("pointer addy: %p", &xPtr);
    else {
        long *temp_ptr = (long*)malloc(sizeof(long));
        //**end = temp_ptr;
        stack = *end;
        *stack = value;
        *end = *end +1;
        //*end = temp_ptr;
    }
}

// This testing code has been provided curteousy of ACME Inc.
//   "Our products are perfectly capable of catching road runners."

void printStack(long **start, long **end) {
    printf("Stack --> [ ");
    if (!isEmpty(*start, *end)) {
        for (int i = 0; *start + i < *end; i++) {
            printf("%ld ", (*start)[i]);
        }
    } 
    printf("]\n");
}

int main () {
    printf("Starting...\n");
    long *start = NULL;
    long *stop = NULL;
    printStack(&start, &stop);
    push(&start, &stop, 1L);
    printStack(&start, &stop);
    push(&start, &stop, 2L);
    printStack(&start, &stop);
    push(&start, &stop, 3L);
    printStack(&start, &stop);
    push(&start, &stop, 4L);
    printStack(&start, &stop);
    push(&start, &stop, 5L);
    printStack(&start, &stop);
   /* 
    long out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop); */
    
/***Expected Output:****

Starting...
Stack --> [ ]
Stack --> [ 1 ]
Stack --> [ 1 2 ]
Stack --> [ 1 2 3 ]
Stack --> [ 1 2 3 4 ]
Stack --> [ 1 2 3 4 5 ]
popped 5
Stack --> [ 1 2 3 4 ]
popped 4
Stack --> [ 1 2 3 ]
popped 3
Stack --> [ 1 2 ]
popped 2
Stack --> [ 1 ]
popped 1
Stack --> [ ]
popped 0
Stack --> [ ]

**********************/
    
}
