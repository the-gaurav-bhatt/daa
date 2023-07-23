//PROGRAM:

#include<stdio.h>
#include<math.h>
#define FALSE 0
#define TRUE 1
int x[20];
// Function to determine if a queen can be placed on board at column k and row i.
int place(int k,int i){
	int j;
	// Running through all previous queens (j=1;j<=k)
	for(j=1;j<=k;j++){
		if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))// Verifying if there's any queen on the ith row or on the diagonals.
			return FALSE; 
	}
	return TRUE; // If no queens found return true
}

// Recursive function to solve N-Queens problem
void nqueens(int k,int n){
	int i,a;
	for(i=1;i<=n;i++)	// For a given kth column we will try all rows from 1 to n to place the queen.
    {
		if(place(k,i))// If a safe place is found for kth queen in ith row, place the queen.
		{
			x[k]=i; // Record in array that kth queen is placed at row i.
			if(k==n){// If all queens are placed
				// Print the board configuration
				for(a=1;a<=n;a++)
					printf("%d\t",x[a]);
				printf("\n");
			}
			else nqueens(k+1,n); // Try to place next queen.
		}
	}
}

void main()
{
	int n;
	
	// Input the number of queens to be placed on a nxn chess board.
	printf("\nEnter the number of queens:");
	scanf("%d",&n);
	printf("\n The solution to N Queens problem is: \n");
	
	// Try to find solutions from the first column
	nqueens(1,n);
}


/* Sample output*/

//Enter the number of queens:4
// The solution to N Queens problem is: 
//2       4       1       3
//3       1       4       2
