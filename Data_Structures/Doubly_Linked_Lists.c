#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


struct node *element(struct node *dll, int i) ;
struct node *add(struct node *dll, int i, int value) ;
struct node *delete(struct node *dll, int i);


struct node {
    int value;
    struct node* next;
    struct node* prev;
};


//returns a pointer to the node at that index
struct node *element(struct node *dll, int i) {
    //node = pointer to next element
    //i = index
    //makes a variable dll which allocates enough memory for next, prev, value

    struct node* ptr = dll;
    for (int count=0 ; count<i ; count++) {   
        ptr = ptr -> next;
    }
    return ptr; 
}






struct node *add(struct node *dll, int i, int value) {
    //i = negative add node to end of list
    struct node* ptr1 = dll;
    struct node* ptr2 = dll;
    //initializing new node
    struct node* new_node = malloc(sizeof(struct node));

    int count = 0;
    while (ptr1 != NULL) {
        ptr1 = ptr1 -> next;
        count++;
       // printf("count: %d\n",count);
    }

//if the i is negative or if index is greater than count, add the new node to the end of the list
    if ((i<0) || (i>=count)) {
        //change next of current end to point to new ptr
        while (ptr2 -> next != NULL) {
            ptr2 = ptr2 -> next;
        }
        ptr2 -> next = new_node;
        new_node -> value = value;
        new_node -> prev = ptr2;
        new_node -> next = NULL;

        return dll;
    }

    //inserting node at beginning of list
    //return value only changes if the new node is inserted at the beginning of the list
    else if (i==0) {
        new_node -> value = value; 
        new_node -> next = ptr2;
        new_node -> prev = NULL;
        ptr2 -> prev = new_node;

        return new_node;
    }

    //inserting node b/w two nodes if count is b/w 0 and i
    else {
        struct node* prev_node;// = malloc(sizeof(struct node));

        //make two new ptrs b/c you are inserting in middle so you need one to left and one to right
        //finding where to insert new node
        for (int m=0 ; m<i ; m++) {
            //points to index
            prev_node = ptr2;
            //points to node right after where you wanna insert
            ptr2 = ptr2 -> next; 
        }

        new_node -> value = value;
        new_node -> next = ptr2;
        new_node -> prev = prev_node;

        prev_node -> next = new_node;
        ptr2 -> prev = new_node;

        return dll;   
    } 
}




struct node *delete(struct node *dll, int i) {
    //pointer for counting 
    struct node* ptr1 = dll;
    //pointer for finding the right spot to delete the node
    struct node* ptr2 = dll;
    //initializing new node
    struct node* new_node = malloc(sizeof(struct node));

    int count = 0;
    while (ptr1 != NULL) {
        ptr1 = ptr1 -> next;
        count++;
        //printf("count: %d\n",count);
    }

//i is negative or if index is greater than count
//deleting the last node
    if ((i==(count-1)) && (count>1)) {
        //struct node* prev_node;
        //ptr2 is the last node
        while (ptr2 -> next != NULL) {
            //prev_node = ptr2;
            ptr2 = ptr2 -> next;
        }
        ptr2 -> prev -> next = NULL;

        free(ptr2);
        return dll;
    }

    else if (i >= count) {
        return dll;
    }


//deleting first node
    else if (i==0) {
        if (count==1) {
            return NULL;
        }
        else {
        //checking prev of the next node after ptr2
        ptr2 -> next -> prev = NULL;

        free(ptr2);
        return ptr2 -> next;
        }
    }


//deleting node b/w two nodes
    else {
        struct node* prev_node;

        //make two new ptrs b/c you are inserting in middle so you need one to left and one to right
        //finding where to insert new node
        //m<=i
        for (int m=0 ; m<=i ; m++) {
            //node at index
            prev_node = ptr2;
            //node after the index
            ptr2 = ptr2 -> next; 
        }

        prev_node -> prev -> next = ptr2;
        ptr2 -> prev = prev_node -> prev;
        
        free(ptr2);
        return dll;   
    } 
}








void printNode (struct node *dll) {
    if (dll != NULL) {
        printf("< This: %p - %d - P : %p - N : %p >\n", dll, dll->value, dll->prev, dll->next);
    } else {
        printf("Null Pointer");
    }
}


void printLL (struct node *dll) {
    struct node* ptr = dll;
    printf("---\n");
    while (ptr != NULL) {
        printNode(ptr);
        ptr = ptr->next;
    }
    printf("---\n\n");
}

int main () {
 
    // Testing code! 
    struct node *dll = malloc(sizeof(struct node));
    dll->value = 1;
    //printf("TESTING element: %d",element(dll,0)-> value);
    printLL(dll);
    
    dll = add(dll, -1, 3);
    printLL(dll);

    dll = add(dll, -1, 4);
    printLL(dll);
    dll = add(dll, 1, 2);
    printLL(dll);
    dll = add(dll, 2, 7);
    printLL(dll);
    dll = add(dll, 9, -1);
    printLL(dll);
 
    dll = delete(dll, 2);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 4);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    dll = delete(dll, 0);
    printLL(dll);
    
}

/* Expected Output: 

---
< This: 0x1cf8590 - 1 - P : (nil) - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8590 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf8610 >
< This: 0x1cf8610 - 7 - P : 0x1cf85f0 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf8610 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

---
< This: 0x1cf8590 - 1 - P : (nil) - N : 0x1cf85f0 >
< This: 0x1cf85f0 - 2 - P : 0x1cf8590 - N : 0x1cf85b0 >
< This: 0x1cf85b0 - 3 - P : 0x1cf85f0 - N : 0x1cf85d0 >
< This: 0x1cf85d0 - 4 - P : 0x1cf85b0 - N : (nil) >
---

*/ 
