#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    int m = 0; //max element;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > m)
        {
            m = a[i];
        }
    }
    int *f = new int[m];
    for (int i = 0; i < n; i++)
    {
        f[a[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (f[i] % 2 == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}