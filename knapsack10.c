#include<stdio.h>
#include<time.h>

// Function to return maximum of two numbers
int max(int x,int y)
{
   return((x>y)?x:y);
}

// Function to solve the knapsack problem using dynamic programming
int knap(int n,int w[10],int value[10],int m,int v[10][10])
{
   int i,j;
   // Fill the table in bottom-up manner
   for(i=0;i<=n;i++)
   for(j=0;j<=m;j++)
    {
      // Base case: If there are no items or capacity is 0, then value is 0
      if(i==0||j==0)
        v[i][j]=0;
      // If weight of the current item is more than capacity, then this item cannot be included in the optimal solution
      else if(j<w[i])
        v[i][j]=v[i-1][j];
      // Return the maximum of two cases: (1) nth item included (2) not included
      else
        v[i][j]=max(v[i-1][j],value[i]+v[i-1][j-w[i]]);
     }
    // Print the table
    printf("\n The table for solving knapsack problem using dynamic programming is:\n");
    for(i=0;i<=n;i++)
     {
      for(j=0;j<=m;j++)
        {
         printf("%d\t",v[i][j]);
         }
      printf("\n");
    }
}

int main()
{
  double clk;
  clock_t starttime,endtime;
  int v[10][10],n,i,j,w[10],value[10],m,result;
  printf("Enter the number of items:");
  scanf("%d",&n);
  printf("Enter the weights of %d items:/n",n);
  for(i=1;i<=n;i++)
   {
     scanf("%d",&w[i]);
   }
   printf("Enter the value of %d items:",n);
   for(i=1;i<=n;i++)
   {
     scanf("%d",&value[i]);
   }
   printf("Enter the capacity of the knapsack:");
   scanf("%d",&m);
   for(i=0;i<=n;i++)
   {
      for(j=0;j<=m;j++)
      {
         v[i][j]=0;
      }
   }
  starttime=clock();
  result=knap(n,w,value,m,v);
  endtime=clock();
  clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
  printf("Optimal solution for the knapsack problem is %d\n",v[n][m]);
  printf("%f\n",clk);
}

/*sample output
Expected output:
Enter the number of items: 4
Enter the weights of 4 items :
2 
1
3
2
Enter the value of 4 items:
12 
10
20
15
Enter the capacity of the knapsack:5
The table for solving knapsack problem using dynamic programming is:
0	0	0	0	0	0
0	0	12	12	12	12
0	10	12	22	22	22
0	10	12	22	30	32
0	10	15	25	30	37
Optimal solution for the knapsack problem is 37
The time taken to sort is 0.989011

*/
