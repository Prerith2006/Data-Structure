#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;

void DFS(int v)
{
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (adj[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    DFS(0);

    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            printf("The graph is NOT connected\n");
            return 0;
        }
    }

    printf("The graph is CONNECTED\n");
    return 0;
}
