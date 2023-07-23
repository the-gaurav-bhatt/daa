#include<stdio.h>
int count,w[10],d,x[10];
// recursive function to find the subsets whose sum of elements is equal to d
void subset(int cs,int k,int r) // cs = current sum, k = level, r = remaining sum
{
   int i;
   x[k]=1; // x[k] is 1 when the element at k is included in subset
   // if current sum plus the current weight equals to destined sum 
   if((cs+w[k])==d)
    {
       printf("\n Subset solution = %d\n",++count);
       for(i=0; i<=k; i++)
       {
         if(x[i]==1)
         printf("%d\n",w[i]);  // print the subset
       }
     }
  else if(cs+w[k]+w[k+1] <=d)  // if it's safe to add the next element to current sum 
        subset(cs+w[k],k+1,r-w[k]);  // then only add and make recursive call
    if((cs+r-w[k]>=d)&&(cs+w[k+1])<=d)
    {
      x[k]=0;  // backtrace and try for another possible solutions
      subset(cs,k+1,r-w[k]);
    }
}
  
int main()
{
    int sum=0,i,n;
    printf("enter no of elements\n");
    scanf("%d",&n);
    printf("Enter the elements in ascending order\n");
    for(i=0; i<n; i++)
    scanf("%d",&w[i]);  // input array elements in ascending order
    printf("Enter the required sum\n");
    scanf("%d",&d); // required sum
    for(i=0; i<n; i++)
    sum +=w[i];  // calculate the sum of all elements
 if(sum < d)
    {
        printf("no solution exists\n");
    }
    printf("The solution is\n");
    count =0;
    subset(0,0,sum); // start with level 0, current sum 0, and total sum
    return 0;
}

