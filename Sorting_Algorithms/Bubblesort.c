#include <stdio.h>
#include <assert.h>
#include <math.h>


int bubblesort(int* x, int size);

int main () {
    int x[] = {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int size = sizeof(x)/sizeof(x[0]);

    int iterations = bubblesort(&x[0], size);
    printf("Iterations: %d\n", iterations);
    return 0;
}




int bubblesort(int* x, int size)
{
    int count = 0;
    for (int i = 0 ; i < size-1 ; i++)
    {   int val;

        for (int j = 0; j < size-i-1 ; j++)
        {
            if(x[j] > x[j+1])
            {
                val = x[j];
                x[j] = x[j+1];
                x[j+1] = val;
                count = count + 1;

            }
        }
    }

    //printing sorted array
    //for (int i=0 ; i < size ; i++)
    //{
        //printf("Number:%d\n",x[i]);
    //}

    return count;
}

