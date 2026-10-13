#include <iostream>
using namespace std;

#define INF 9999

int main()
{
    int n, source;
    int cost[10][10], dist[10], visited[10] = {0};

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter cost adjacency matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (i != j && cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    cout << "Enter source vertex (0 to " << n - 1 << "): ";
    cin >> source;

    for (int i = 0; i < n; i++)
        dist[i] = cost[source][i];

    dist[source] = 0;
    visited[source] = 1;

    for (int count = 1; count < n; count++)
    {
        int min = INF, u = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && cost[u][v] != INF &&
                dist[u] + cost[u][v] < dist[v])
            {
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    cout << "\nShortest distances from source " << source << ":\n";

    for (int i = 0; i < n; i++)
    {
        if (dist[i] == INF)
            cout << "Vertex " << i << " : Unreachable\n";
        else
            cout << "Vertex " << i << " : " << dist[i] << endl;
    }

    return 0;
}