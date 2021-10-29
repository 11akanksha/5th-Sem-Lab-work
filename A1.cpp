#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> *aL, int u, int v)
{
    aL[u].push_back(v);
    aL[v].push_back(u);
}

int main()
{
    int n;
    cout << "Enter the no of nodes of the graph:\n";
    cin >> n;
    vector<int> adjL[n];
    cout << "Enter the edges:" << endl;
    int a, b;
    bool add_more = true;

    do
    {
        cin >> a >> b;
        addEdge(adjL, a, b);

        cout << "Continue?\t";
        cin >> add_more;
    } while (add_more);

    cout << "Adjacency list:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i;
        for (auto x : adjL[i])
            cout << " -> " << x;
        cout << endl;
    }
    return 0;
}