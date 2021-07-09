#include <iostream>
using namespace std;

void swap_ele(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void sort_arr(int *a, int l)
{
    for (int i = 0; i < l - 1; i++)
    {
        for (int j = 0; j < l - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap_ele(&a[j], &a[j + 1]);
            }
        }
    }
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
    int m;
    cin >> m;
    int *b = new int[m];
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int *c = new int[n + m];
    sort_arr(a, n);
    sort_arr(b, m);
    for (int i = 0; i < (n + m); i++)
    {
        if (i < n)
        {
            c[i] = a[i];
        }
        else
        {
            c[i] = b[i - n];
        }
    }
    sort_arr(c, m + n);
    for (int i = 0; i < m + n; i++)
    {
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}