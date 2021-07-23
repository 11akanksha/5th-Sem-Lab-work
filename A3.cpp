#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void sort_arr(int *a, int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;

        swap(&a[min_idx], &a[i]);
    }
}

int main()
{
    int n, min_diff = INT_MAX;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort_arr(a, n);
    for (int i = 1; i < n; i++)
    {
        int diff = a[i] - a[i - 1];
        if (diff < min_diff)
            min_diff = diff;
    }
    cout << min_diff;
    delete[] a;
    return 0;
}