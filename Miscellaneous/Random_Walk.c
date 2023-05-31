#include<stdio.h>

int* walk(int board[10][10], int* start) ;

int main() {
	int board[10][10] = { {5,3,4,5,7,5,9,9,1,9}
					, {7,6,2,3,1,6,5,4,7,2}
					, {2,1,1,2,2,8,7,9,2,2}
					, {3,4,6,5,4,3,5,4,1,4}
					, {7,3,9,1,6,1,3,4,2,6}
					, {2,8,4,8,3,2,1,1,5,2}
					, {2,1,5,5,4,6,8,5,4,3}
					, {4,4,1,8,1,2,2,7,1,2}
					, {6,2,5,8,5,1,6,7,4,4}
					, {2,2,8,3,1,7,7,3,8,5}
					};
	
	int* tests[4]     = {&board[8][3], &board[6][7], &board[1][2], &board[8][0]};
	int* solutions[4] = {&board[6][3], &board[6][7], &board[5][1], &board[9][1]};
	 // 1: U, U, 5 Stop 
	 // 2: 5 Stop
	 // 3: D, DL, L, DR, DR, L, Loop Stop
	 // 4: R, D, D, Edge Stop
	
	for (int i = 0; i < 4; i++) {
		printf("Test %d, starting at address %p ", i, tests[i]);
		if (walk(board, tests[i]) == solutions[i]) {
			printf("Passes!\n");
		} else {
			printf("Fails!\n");
		}	
	}
}



/*
int* start(int board[10][10], int* start) 
{
	int address;
	for(int i=0;i<10;i++){
		for (int j=0;j<10;j++){
			if(&board[i][j] == start){
				printf("i=%d,j=%d:", i,j);
				return i,j;
	
			}
		}
	}

	//return i,j;


}*/
int* walk(int board[10][10], int* start) {


	int address;
	for(int m=0;m<10;m++){
		for (int n=0;n<10;n++){
			if(&board[i][j] == start){
				printf("i=%d,j=%d:", m,n);
				return m,n;
	
			}
		}
	}

	while (*board[m][n] != 5 && (m != 0) && (m != 10) && (n != 0) && (n != 10)){

		if (*board == 1){
			&board[m+1][n-1];  
		}

		else if (*board == 2){
			&board[m+1][n];  
		}

		else if (*board == 3){
			&board[m+1][n+1];  
		}
		else if (*board == 4){
			&board[m][n-1];  
		}

		else if (*board == 6){
			&board[m][n+1];  
		}

		else if (*board == 7){
			&board[m-1][n-1];  
		}

		else if (*board == 8){
			&board[m-1][n];  
		}

		else if (*board == 9){
			&board[m-1][n+1];  
		}

	}

	return &board; 

}
/*
int stop(int board[10][10],int m, int n){
	if
}
*/



        
