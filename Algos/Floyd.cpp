// DP Based, TC = O(V^3) ,SC = O(V^2)
#include <iostream>
#include <vector>
#define INF 10000
// INF is defined instead of using INT_MAX to avoid overflow
using namespace std;

vector<vector<int>> floydWarshall(vector<vector<int>> gr)
{
    // Initialize distance vector having same values as gr
    vector<vector<int>> distance(gr);
    int V = gr.size();
    // Phases: in kth phase we include (1,2,...k) as intermediate vertices
    for (int k = 0; k < V; k++)
    {
        // Iterate over the entire 2D matrix
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (distance[i][j] > distance[i][k] + distance[k][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    return distance;
}

// Detecting negative weight cycle:
bool detectNegCycle(vector<vector<int>> d)
{
    int V = d.size();
    int k = V - 1;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (d[i][j] > d[i][k] + d[k][j])
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> graph = {
        {0, INF, -2, INF},
        {4, 0, 3, INF},
        {INF, INF, 0, 2},
        {INF, -1, INF, 0}};

    auto result = floydWarshall(graph);

    bool outcome1 = detectNegCycle(result);
    if (outcome1)
    {
        cout << "Negative weight cycle detected!" << endl;
    }
    else
    {
        cout << "Negative weight cycle is not present" << endl;
        int l1 = result.size();
        for (int i = 0; i < l1; i++)
        {
            for (int j = 0; j < l1; j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    vector<vector<int>> graph2 = {
        {0, 3, INF},
        {INF, 0, 4},
        {-10, INF, 0}};

    auto res = floydWarshall(graph2);

    bool outcome2 = detectNegCycle(res);
    if (outcome2)
    {
        cout << "Negative weight cycle detected!" << endl;
    }
    else
    {
        cout << "Negative weight cycle is not present" << endl;
        int l2 = res.size();
        for (int i = 0; i < l2; i++)
        {
            for (int j = 0; j < l2; j++)
            {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
