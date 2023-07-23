#include<stdio.h>
#include<time.h>

#define MAX 10

// Function to choose the vertex with the minimum distance value, from the set of vertices not yet included in shortest path tree
int choose(int dist[],int s[],int n)
{
  int j=1,min=100,w;
  for(w=1;w<=n;w++)
   if((dist[w]<min) && (s[w]==0)) // If vertex w is not in shortest path tree and dist[w] is smaller than current min
     {
       min=dist[w]; // Update min
       j=w;
     }
   return j; // Return the vertex with minimum distance value
}

// Function to implement Dijkstra's single source shortest path algorithm for a graph represented using adjacency matrix representation
void spath(int v,int cost[][MAX],int dist[],int n)
 {
    int w,u,i,num,s[MAX];
    for(i=1;i<=n;i++)
     {
        s[i]=0; // Initialize s[] as false which means that vertex i is not included in the shortest path tree
        dist[i]=cost[v][i]; // Initialize all distances as cost from source vertex
     }
     s[v]=0; // Include source vertex in shortest path tree
     dist[i]=999; // Maximum possible value
     for(num=2;num<=n;num++)
      {
        u=choose(dist,s,n); // Pick the minimum distance vertex from the set of vertices not yet included in shortest path tree
        s[u]=1; // Include u to shortest path tree
        for(w=1;w<=n;w++)
          if((dist[u]+cost[u][w])<dist[w] && !s[w]) // Update dist[w] only if it is not in s[], there is an edge from u to w, and total weight of path from v to w through u is smaller than current value of dist[w]
            dist[w]=dist[u]+cost[u][w];  
      } 
 }

void main()
{
   int i,j,cost[MAX][MAX],dist[MAX],n,v;
   double clk;
   clock_t starttime,endtime;

   printf("\nEnter number of vertices:");
   scanf("%d",&n);
   printf("\nEnter the cost of adjacency matrix\n");
   for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
       scanf("%d",&cost[i][j]); // Input the cost of adjacency matrix
   printf("\nEnter the source vertex");
   scanf("%d",&v); // Input the source vertex

   starttime=clock(); // Start the clock
   spath(v,cost,dist,n); // Call the function to find shortest path
   endtime=clock(); // End the clock
   printf("\nShortest  distance\n");
   for(i=1;i<=n;i++)
       printf("\n%d to %d = %d",v,i,dist[i]); // Print the shortest distance from source to i
   clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
   printf("The time taken is %f\n",clk); // Print the time taken to find shortest path

}
