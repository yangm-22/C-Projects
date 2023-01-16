#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

//* is actual value 
double mean(int* x, int size);
double median(int* x, int size);
int mode(int* x, int size);



int main () {
    int x[] = {99,5,5,9,99,2,1,99};
    int size = sizeof(x)/sizeof(x[0]);

    //& is the address of the item
    double mean_val = mean(&x[0], size);
    printf("Mean is %f\n", mean_val);

    double median_val = median(&x[0], size);
    printf("Median is %f\n", median_val);

    int mode_val = mode(&x[0], size);
    printf("Mode is %d\n", mode_val);
    return 0;
}


// int*x = array 
// size = size of array
double mean(int* x, int size)
{
    double total = 0;
    for (int i=0; i<size; i++)
    {
        total = total + *(x+i);
        //printf("%f",total);
    }

    double mean_val = total/size;

    return mean_val;

}




double median(int* x, int size)
{
    double median_val = -1.0;

    for (int i=0 ; i < size-1 ; i++)
    {
        int val;

        for (int j = 0; j<size-i-1 ; j++)
        {
            if(x[j] > x[j+1])
            {
                val = x[j];
                x[j] = x[j+1];
                x[j+1] = val;

            }
        }
    }

   // for (int i=0 ; i < size ; i++)
    //{
        //printf("Number:%d",x[i]);
    //}
    if (size % 2 == 0)
    {
        median_val = (x[size/2] + x[size/2 - 1])/2.0;
    }

    else 
    {
        int index = floor(size/2) ;
        median_val = x[index];
    }
    return median_val ;
}



int mode(int* x, int size)
{
    int mode_count = 0;
    int mode_val = 0;

    int current_mode_num = 0;
    //int current_mode_times = 0;
    int flag = 0;


    //int mode_count2 = 0;
    //int mode_val2 = 0;

    for (int i = 0 ; i < size ; i++)
    {
        
        int count = 0;
        
        for (int j = 0 ; j < size ; j++)
        {
            //printf("x[j]:%d--x[i]:%d\n",x[j],x[i]);
            if (x[j] == x[i])
            {
                //printf("x[j]:%d--x[i]:%d\n",x[j],x[i]);
                count = count + 1;
                //printf("count:%d\n",count);
            }

            else if (x[i] == mode_val)
            {
                break;
            }

            if ((count > mode_count) && (count != 0))
            {
                mode_count = count;
                mode_val = x[i];
                flag = 1;
            }
            else if (count == mode_count)
            {
                flag = 0;
            }
            
        }
    }

    if (flag != 1)
        {
             mode_val = -1;
        }
        
        return mode_val;

    }


