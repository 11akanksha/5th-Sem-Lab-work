#include <iostream>
#define max 100
using namespace std;

int main()
{
    int n, t1, t2, n1;
    int a[max];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    if (n % 2 != 0)
        n1 = n - 1;
    else
        n1 = n;
    int k = n1;
    for (int i = 0; i < n1 / 2 - 1; i = i + 2)
    {
        t1 = a[i];
        t2 = a[i + 1];
        a[i] = a[k - 2];
        a[k - 2] = t1;
        a[i + 1] = a[k - 1];
        a[k - 1] = t2;
        k = k - 2;
    }
    for (int i = 0; i < n; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}