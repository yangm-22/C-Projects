#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size));
int bubblesort (int* x, int size);

int main () 
{
    int array_t[] = {135, 529, 81, 54, 46, 605, 47, 793, 278, 323, 306, 430, 973, 286, 712, 962, 461, 81, 57, 325, 711, 995, 833, 222, 284, 293, 153, 224, 126, 643, 425, 400, 420, 309, 831, 6, 496, 347, 185, 583};
    //int array_t[] = {44, 79, 8, 53, 93, 21, 70, 79, 82, 49, 25, 2, 62, 26, 29, 54, 89, 57, 74, 39};
    //int array_t[] = {4,6,100,25,6,17,29,80,19,40,30,35,198,209,3,10,249};
    //int array_t[] = {0,2,42,43,6,3,65,34,29,29,48,32,10,432,543,194,29,84,29};
    int size = sizeof(array_t)/sizeof(array_t[0]);
    int h_gaps[] = {10, 4, 1};

    //loop for returning number of swaps and adding them together to find total swaps
    int count_swaps = shellsort(&array_t[0], size, h_gaps, bubblesort);
    //int arry2[]={29,62,74,89};
    //int swaps = bubblesort(&array_t[0], 4);

    //for(int i=0;i<4;i++){
     //       printf("arry2[%d]:%d\n",i, arry2[i]);
     //   }
    printf("\nswaps: %d \n",count_swaps);

    return 0;
}



int shellsort (int *array, int size, int *h_gaps, int (*subsort)(int* array, int size)) 
{
    //int size_hgaps = sizeof(h_gaps)/h_gaps[0];
    int swap = 0, count_swaps = 0;
    while (*h_gaps != 0)
    {
        //printf("hgaps:%d\n", *h_gaps);
        int tmp_gap = *h_gaps;
        int last_element_checked = -1;
        //printf("H_Gaps:%d\n",tmp_gap);
        for(int i=0;i<tmp_gap;i++){
            //int* pt_tmp_array = (int *)malloc(size_tmp_array*sizeof(int));
            //int size_tmp_array = ceil(size / (tmp_gap + 1.0));
            int size_tmp_array = (int)ceil((float)size/tmp_gap);

            //CHANGE THIS CONDITION
            if(last_element_checked == 1){
                size_tmp_array = size_tmp_array - 1;
            }
            //printf("size_tmp_array:%d\n", size_tmp_array);
            int tmp_array[size_tmp_array]; 
            //pt_tmp_array = &tmp_array[0];
            //assign sub array
            for(int j=0,k=i;j<size_tmp_array && k<size;j++,k += tmp_gap){
                tmp_array[j] = array[k];
                if(k == size - 1){
                    last_element_checked = 1;
                    //printf("last_element_checked:%d\n", last_element_checked);
                }
                 //printf("tmp_array[%d]:%d\n", j,tmp_array[j]);
            }
            //sort sub array
            /*
            printf("sub array:");
            for(int i=0;i<size_tmp_array;i++)
             {
                printf("%d,", tmp_array[i]);
            }
            printf("\n"); */
            swap = subsort(&tmp_array[0],size_tmp_array);
            /*
            printf("sub array:");
             for(int i=0;i<size_tmp_array;i++)
             {
                printf("%d,", tmp_array[i]);
            }
            */

            //printf("--->count swap:%d\n",swap);
            count_swaps += swap;
            //assign back to original array   
            for(int j=0,k=i;j<size_tmp_array && k<size;j++,k += tmp_gap){
                array[k] = tmp_array[j];
            } 
        }
        //printf("count_swap for hgaps %d:%d\n", *h_gaps,count_swaps);
        h_gaps += 1 ;
    }
    /*
    printf("Current Array after Shell Sort:");
    for(int i=0;i<size;i++)
    {
        printf("%d,",array[i]);
    }
    */

    swap = subsort(&array[0],size);
    count_swaps += swap;
    /*
    printf("\nSorted Array :");
    for(int i=0;i<size;i++)
    {
        printf("%d,",array[i]);
    } */
    
    return count_swaps;
}


int bubblesort(int* x, int size) {
    int temp; 
    int swaps = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (x[j] > x[j+1]) {
                //printf("Swaping J->%d:%d-->%d\n",j,x[j],x[j+1]);
                temp = x[j];
                x[j] = x[j + 1];
                x[j+1] = temp;
                swaps ++;
            }
        }
    }
    return swaps;
}

