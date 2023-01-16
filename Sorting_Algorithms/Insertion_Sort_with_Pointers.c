#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int insertionsort(int* x, int size, int (*compare)(int a, int b));
int ascending (int a, int b);
int descending (int a, int b);
void swap (int* num1, int* num2);


int main () 
{
    //int x[] = {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int x[] = {2,10,0,88,92,193,69,392,41,329,302,30,1,0,2,19,2};
    int size = sizeof(x)/sizeof(x[0]);

    //printing the number of examinations
    int examinations = insertionsort(x, size, descending);
    printf("Examinations: %d \n", examinations);
    /*for (int i=0 ; i>size ; i++)
    {
        printf("x[%d]: %d", i,x[i]);
    }
    */

    return 0;
}



//insertion sort from assignment 2
int insertionsort(int* x, int size, int (*compare)(int a, int b))
{
    void swap(int* num1, int* num2);

    //number of examinations => counter
    int counter = 0;
    int temp;

    for (int i=0 ; i<size-1 ; i++)
    {
        for (int j=i+1 ; j>0 ; j--)
        {
            counter += 1;
            if (compare(x[j-1],x[j]))
            {
                //swap the addresses
                swap(&x[j-1],&x[j]);
                printf("x[j-1]= %d...x[j]= %d \n", x[j-1],x[j]);
            }

            else
            {
                break;
            }
        }
    }
    return counter; 
}








int ascending (int a, int b)
{
    //swap if b is less than a
    return b < a;

}



int descending (int a, int b)
{
    //swap if b is greater than a
    return b > a; 

}



void swap (int* num1, int* num2)
{
    //swapping 
    int hold = *num1;
    *num1 = *num2;
    *num2 = hold; 
    
}


