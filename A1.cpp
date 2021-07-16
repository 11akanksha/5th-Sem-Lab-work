#include <iostream>
using namespace std;

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void sort(int *a, int n)
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
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, n);
    cout << "Second smallest:" << a[1] << endl;
    cout << "Second largest:" << a[n - 2] << endl;
    delete[] a;
    return 0;
}