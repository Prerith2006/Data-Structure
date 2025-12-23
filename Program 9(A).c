#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;
int visited[MAX];
int adj[MAX][MAX];
int n;

void enqueue(int value)
{
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue()
{
    int value = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return value;
}

void BFS(int start)
{
    int i, v;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front != -1)
    {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        for (j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    return 0;
}
