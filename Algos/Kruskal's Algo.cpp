#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
    //E : No of edges
    int E;
    vector<vector<int>> edges;

public:
    Graph(int e)
    {
        E = e;
        edges.resize(E);
    }

    void addEdges(int i, int x, int y, int w)
    {
        edges[i] = {w, x, y};
    }

    int findSet(int e, int *parent)
    {
        if (e == parent[e])
        {
            return e;
        }
        return parent[e] = findSet(parent[e], parent);
    }

    void doUnion(int a, int b, int *parent, int *rank)
    {
        int S1 = findSet(a, parent);
        int S2 = findSet(b, parent);

        if (S1 != S2)
        {
            if (rank[S1] < rank[S2])
            {
                parent[S1] = S2;
                rank[S2] += rank[S1];
            }
            else
            {
                parent[S2] = S1;
                rank[S1] += rank[S2];
            }
        }
    }

    int kruskalsAlgo(int N)
    {
        int ans = 0;
        int *parent = new int[N];
        int *rank = new int[N];
        for (int i = 0; i < N; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
        sort(edges.begin(), edges.end());
        for (int i = 0; i < E; i++)
        {
            int x = edges[i][1];
            int y = edges[i][2];
            int w = edges[i][0];
            if (findSet(x, parent) != findSet(y, parent))
            {
                doUnion(x, y, parent, rank);
                ans += w;
            }
        }
        delete[] parent;
        delete[] rank;
        return ans;
    }
};
int main()
{
    int noOfNodes, noOfEdges;
    cin >> noOfNodes >> noOfEdges;
    Graph G(noOfEdges);

    for (int i = 0; i < noOfEdges; i++)
    {
        int a, b, wt;
        cin >> a >> b >> wt;
        a--;
        b--;
        G.addEdges(i, a, b, wt);
    }

    cout << G.kruskalsAlgo(noOfNodes) << endl;
    return 0;
}

//i/p:
9 15
1 2 10
1 3 12
2 3 9
2 4 8
3 5 3
3 6 1
5 4 7
4 6 10
4 7 8
4 8 5
6 8 6
8 7 9
8 9 11
7 9 2
5 6 3
  
//O/p:
43
