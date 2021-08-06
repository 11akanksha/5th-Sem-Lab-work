#include <iostream>
using namespace std;

void solve(int n)
{
    if (n == 1)
    {
        cout << "we reached 1" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    solve(n - 2);
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}