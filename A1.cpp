#include <iostream>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        ans = ans ^ a[i];
    }
    cout << ans;
    delete[] a;
    return 0;
}