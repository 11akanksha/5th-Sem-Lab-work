#include <iostream>
#include <vector>
using namespace std;

vector<int> bellmanFord(int no_vertices, int src, vector<vector<int>> e)
{
    // Step 1 : Initialize the distance vector
    vector<int> distance(no_vertices + 1, INT_MAX);
    distance[src] = 0;

    // Step 2 : Relaxation[all edges,(no_vertices - 1) times]
    for (int i = 0; i < no_vertices - 1; i++)
    {
        for (auto edge : e)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            if (distance[u] != INT_MAX and distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }
    // Detect -ve weight cycle:
    for (auto edge : e)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if (distance[u] != INT_MAX and distance[u] + w < distance[v])
        {
            cout << "Negative weight cycle found" << endl;
            // exit the program
            exit(0);
        }
    }
    return distance;
}

int main()
{
    int no_vertices, no_edges;
    cin >> no_vertices >> no_edges;
    // edge list:
    vector<vector<int>> edges;

    for (int i = 0; i < no_edges; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    // Assuming the nodes to be numbered from 1 to no_vertices
    // call Bellman Ford function:
    vector<int> dist = bellmanFord(no_vertices, 1, edges);
    for (int i = 1; i <= no_vertices; i++)
    {
        cout << "Node " << i << " is at a distance of " << dist[i] << endl;
    }
    return 0;
}
