#include<stdio.h>

int highfives (char hall[]) ;

int main () {
	char hall1[] = ">><<";
	char hall2[] = ">-<<->----<><>>-";
	char hall3[] = ">-<->--<<>><->-<-->-<--->-<>->>->>-<<<->";
	printf("Hall 1 should have 4 high fives.  You got %d\n", highfives(hall1));
	printf("Hall 2 should have 7 high fives.  You got %d\n", highfives(hall2));
	printf("Hall 3 should have 63 high fives.  You got %d\n", highfives(hall3));
}

int highfives (char hall[]) 
{
	int len = 0;
	int index = 0;
	int count = 0;

	while (hall[index] != '\0')
	{
		index++;
		len++;
	}

	for (int j=0 ; j<len ; j++)
	{
		if (hall[j] == '>')
		{
			for (int m=j+1; m<len ; m++)
			{
				if (hall[m]=='<')
				{
					count++;
				}
			}
		}
	}

	return count;
}
