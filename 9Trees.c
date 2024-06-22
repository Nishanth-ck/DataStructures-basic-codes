#include<stdio.h>
#include<stdlib.h>

void bfs(int n,int a[20][20],int source,int visited[],int e[20][2])
{
    int f=0,r=-1,q[20];
    int u, v, k = 1;

    visited[source] = 1;
    r = r+1;
    q[r] = source;

    while(f<=r)
    {
        u = q[f];
        f = f + 1;

        for (v = 1; v <= n; v++)
        {
            if(a[u][v]==1 && visited[v]==0)
            {
                visited[v] = 1;
                r = r+1;
                q[r] = v;

                e[k][1] = u;
                e[k][2] = v;
                k = k + 1;
            }
        }
    }
}

void dfs(int n,int a[20][20],int u,int visited[],int e[20][2])
{
    int v;
    static int k = 1;

    visited[u] = 1;

    for (v = 1; v <= n; v++)
    {
        if (a[u][v] == 1 && visited[v] == 0)
        {
            e[k][1] = u;
            e[k][2] = v;
            k = k + 1;

            dfs(n, a, v, visited, e);
        }
    }
}

void main()
{
    int n,i,j,a[20][20],source,visited[20],e[20][2],choice,flag;

    printf("\nEnter the number of vertices:");
    scanf("%d",&n);

    printf("\nEnter the adjacency matrix:");
    for (i = 1;i<=n;i++)
    {
        for (j = 1; j <= n;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter the source:");
    scanf("%d", &source);

    for (i = 1; i <= n;i++)
    {
        visited[i] = 0;
    }

    printf("\n1.BSF     2.DFS\n");
    printf("\nEnter your choice");
    scanf("%d",&choice);

    if(choice == 1)
        bfs(n, a, source, visited, e);
    else
        dfs(n, a, source, visited, e);

    flag = 0;
    for(i=1;i<=n;i++)
    {
        if(visited[i] == 0)
        {
            printf("\nThe node %d is not reachable :", i);
            flag = 1;
        }

        else
        {
            printf("\nThe node %d is reachable:", i);
        }
    }

    if(flag == 1)
    {
        printf("\nThe graph is not connected:");
    }
    else
    {
        printf("\nThe graph is connected:");
        printf("\nThe spanning tree or traversal is:");
        for(i=1;i<=n-1;i++)
        {
            printf("\nEdge from %d to %d", e[i][1], e[i][2]);
        }
    }
}
