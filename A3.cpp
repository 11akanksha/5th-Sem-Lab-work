#include <iostream>
#include <vector>
using namespace std;

bool detectCycle(vector<int> *aL, int v, bool vis[], int p)
{
    vis[v] = true;
    for (int i = 0; i < aL[v].size(); i++)
    {
        if (!vis[i])
        {
            if (detectCycle(aL, i, vis, v))
                return true;
        }
        else if (i != p)
            return true;
    }
    return false;
}

bool hasCycle(vector<int> *aL, int n)
{
    bool *vis = new bool[n];
    for (int i = 0; i < n; i++)
        vis[i] = false;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            if (detectCycle(aL, i, vis, -1))
                return true;
    }
    return false;
}

void addEdge(vector<int> *aL, int u, int v)
{
    aL[u].push_back(v);
    aL[v].push_back(u);
}

int main()
{
    int n = 5;
    vector<int> adjL[n];
    addEdge(adjL, 0, 1);
    addEdge(adjL, 0, 2);
    addEdge(adjL, 1, 4);
    addEdge(adjL, 2, 4);
    addEdge(adjL, 2, 3);

    cout << "Adjacency list:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i;
        for (auto x : adjL[i])
            cout << " -> " << x;
        cout << endl;
    }
    cout << endl;

    hasCycle(adjL, n) ? cout << "The graph has a cycle\n" : cout << "The graph has no cycles\n";

    return 0;
}