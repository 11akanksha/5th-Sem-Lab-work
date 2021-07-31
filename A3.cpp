#include <iostream>
using namespace std;

int main()
{
    int a[10][10];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int k = 0; k < n; ++k)
    {
        int c1 = 0;
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (a[0][k] == a[i][j])
                {
                    c1++;
                    break;
                }
            }
        }
        if (c1 == n - 1)
            cout << a[0][k] << " ";
    }
    cout << endl;
    return 0;
}