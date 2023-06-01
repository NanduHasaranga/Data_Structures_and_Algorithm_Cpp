#include <iostream>
#include <limits>
using namespace std;

#define max 6
#define INFINITY 9999

int minDistance(int dist[], bool visitedSet[])
{
    int min = INFINITY, min_index;

    for (int v = 0; v < max; v++)
        if (visitedSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printShortestPath(int dist[], int parent[], int startNode)
{
    cout<< "Time Taken From City "<< startNode<<endl<<endl;
    for (int i = 0; i < max; i++)
    {
        if (i != startNode)
        {
            cout<< "Distance of node " << i << " = " << dist[i] << endl;
            int j = i;
            cout << "Path = "<< j;
            while (parent[j] != -1)
            {
                cout << "<-" << parent[j];
                j = parent[j];
            }
            cout << endl;
        }
    }
}

void dijkstra(int graph[max][max],int startNode)
{
    int dist[max];
    int parent[max];
    bool visitedSet[max];

    for (int i = 0; i < max; i++)
    {
        dist[i] = INFINITY;
        parent[i] = -1;
        visitedSet[i] = false;
    }

    dist[startNode] = 0;

    for (int count = 0; count < max - 1; count++)
    {
        int u = minDistance(dist, visitedSet);

        visitedSet[u] = true;

        for (int v = 0; v < max; v++)
        {
            if (!visitedSet[v] && graph[u][v] && dist[u] != INFINITY && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printShortestPath(dist, parent, startNode);
}

int main() {
    int graph[max][max] = {{0 , 10, 0 , 0 , 15, 5},
                           {10, 0 , 10, 30, 0 , 0},
                           {0 , 10, 0 , 12, 5 , 0},
                           {0 , 30, 12, 0 , 0 , 20},
                           {15, 0 , 5 , 0 , 0 , 0},
                           {5 , 0 , 0 , 20, 0 , 0}};

    dijkstra(graph, 5);
    return 0;
}
