#include <stdio.h>
#include <assert.h>
#include <math.h>


int insertionsort(int* x, int size);

int main () {
    int x[] = {548, 845, 731, 258, 809, 522, 73, 385, 906, 891, 988, 289, 808, 128};
    int size = sizeof(x)/sizeof(x[0]);

    int examination = insertionsort(&x[0], size);
    printf("Examinations: %d\n", examination);

    //printing sorted array
    //printf("{");
    //for (int i=0 ; i < size ; i++)
    //{
        //printf("%d, ",x[i]);
    //}
    //printf("} \n");

    return 0;
}


int insertionsort(int* x, int size)
{
    int counter = 0;
    for (int i = 1 ; i < size ; i++)
    {
        int num = x[i];
        int j = i - 1;

        while (num < x[j] )
        {   
            x[j+1] = x[j];
            j = j - 1;
            if(j>=0){
                counter = counter + 1;
            }
            else{
                break;
            }
            
            //printf("J: %d\n", j);
        }

        x[j+1] = num;
        counter++;
    }

    return counter; 
}

