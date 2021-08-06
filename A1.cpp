#include <iostream>
using namespace std;

void solve(int n)
{
    if (n == 1)
    {
        cout << n << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    solve(n - 1);
}

int main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}