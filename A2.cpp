#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<int>> &aM, int u, int v, int wt)
{
    aM[u][v] = wt;
    aM[v][u] = wt;
}

int main()
{
    int n;
    cout << "Enter the no of nodes of the graph:\n";
    cin >> n;
    vector<vector<int>> adjM(n, vector<int>(n, 0));
    cout << "Enter the weighted edges:" << endl;
    int a, b, w;
    bool add_more = true;

    do
    {
        cin >> a >> b >> w;
        addEdge(adjM, a, b, w);

        cout << "Continue?\t";
        cin >> add_more;
    } while (add_more);

    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adjM[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}