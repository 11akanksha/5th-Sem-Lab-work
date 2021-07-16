#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s = n;
    if (n % 2 != 0)
    {
        int s = n - 1;
    }
    for (int i = 0; i < s / 2; i++)
    {
        swap(a[i], a[(s - 1) - i]);
    }
    for (int i = 0; i < s; i += 2)
    {
        swap(a[i], a[i + 1]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}