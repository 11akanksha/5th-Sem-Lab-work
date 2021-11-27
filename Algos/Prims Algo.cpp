#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adjacencyList[n + 1];
    bool visited[n + 1] = {};
    //Hence initially all values in the visited array are 0 (false)
    for (int i = 0; i < m; i++)
    {
        int x, y, wt;
        cin >> x >> y >> wt;
        adjacencyList[x].push_back(make_pair(y, wt));
        adjacencyList[y].push_back({x, wt});
    }
    //This will help us to select a minimum wt edge and the vertex connected to it
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    //Enter a node to start with
    cout << "Which node to start with?" << endl;
    int st;
    cin >> st;
    Q.push({0, st});
    //{Weight,Node}

    long long int mst = 0;
    while (!Q.empty())
    {
        pair<int, int> best = Q.top();
        Q.pop();
        int selectedWt = best.first;
        int pointingTo = best.second;
        //Not an active edge:
        if (visited[pointingTo])
            continue;
        //An active edge:
        mst += selectedWt;
        visited[pointingTo] = true;
        //pointingTo is visited now
        for (auto x : adjacencyList[pointingTo])
        {
            //if its neighbour is not visited:
            if (!visited[x.first])
            {
                Q.push({x.second, x.first});
            }
        }
    }
    cout << mst << endl;
    return 0;
}
//i/p:
9 15
1 2 10
2 3 9
1 3 12
3 5 3
2 4 8
5 4 7
3 6 1
5 6 3
6 4 10
6 8 6
8 4 5
4 7 8
7 8 9
7 9 2
8 9 11
Which node to start with?
1

//o/p:
43  
