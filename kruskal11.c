#include<stdio.h>
#include<time.h>
// Define a structure to represent an edge in the graph
struct edge
{
     int u,v,cost;
};
typedef struct edge edge;

// Function to find the parent of a node in the disjoint set
int find(int v,int parent[])
{
    // Keep traversing up the tree until we find a node that is its own parent
    while(parent[v]!=v)
     {
       v=parent[v];
     }
   return v; // Return the ultimate parent (root) of v
}

// Function to perform union of two subsets
void union_ij(int i,int j,int parent[])
{
     // Make the smaller element the parent of the larger one
     if(i<j)
       parent[j]=i;
    else
       parent[i]=j;
}

// Function to implement Kruskal's algorithm
void kruskal(int n,edge e[],int m)
{
     int count,k,i,sum,u,v,j,t[10][10],p,parent[10];
     edge temp;
     count=0;
     k=0;
    sum=0;

   // Sort the edges in increasing order of cost
   for(i=0;i<m;i++)
    {
       for(j=0;j<m-1;j++)
        {
            if(e[j].cost>e[j+1].cost)
              {
                // Swap e[j] and e[j+1]
                temp.u=e[j].u;
                temp.v=e[j].v;
                temp.cost=e[j].cost;
                e[j].u=e[j+1].u;   
                e[j].v=e[j+1].v;
                e[j].cost=e[j+1].cost;
                e[j+1].u=temp.u;
                e[j+1].cost=temp.cost;
                }
          }
    }

   // Initialize parent array so that each node is its own parent
   for(i=0;i<n;i++)
   parent[i]=i;
   p=0;

   // Keep adding edges to the spanning tree until we have n-1 edges
   while(count!=n-1)
    {
        // Pick the smallest edge that does not form a cycle
        u=e[p].u;
        v=e[p].v;
        i=find(u,parent);
        j=find(v,parent);
        if(i!=j) // If u and v are not in the same subset, i.e., there is no cycle
        {
            t[k][0]=u;
            t[k][1]=v;
            k++;
            count++;
            sum+=e[p].cost;
            union_ij(i,j,parent); // Merge u and v's subsets
        }
        p++;
    }

    // If we found a spanning tree
    if(count==n-1)
    {
        printf("Spanning tree exists\n");
        printf("The spanning tree is as follows:\n");
        for(i=0;i<n-1;i++)
        {
            printf("%d  %d\t",t[i][0],t[i][1]);
        }
        printf("\nThe cost of the spanning tree is %d\n",sum);
     }
    else
        printf("\n spanning tree does not exist");
}

// Main function
void main()
{
    int n,m,a,b,i,cost;
    double clk;
    clock_t starttime,endtime;
    edge e[20];

    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("Enter the number of edges:\n");
    scanf("%d",&m);
    printf("Enter the edge list( u  v  cost)\n");

    // Read the edges
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&cost);
        e[i].u=a;
        e[i].v=b;
        e[i].cost=cost;
    }

    // Measure the time taken by Kruskal's algorithm
    starttime=clock();
    kruskal(n,e,m);
    endtime=clock();
    clk=(double)(endtime-starttime)/CLOCKS_PER_SEC;
    printf("The time taken is %f\n",clk);
}
