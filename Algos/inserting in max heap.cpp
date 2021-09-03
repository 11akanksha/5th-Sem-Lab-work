#include <iostream>
using namespace std;

void max_heapify(int *a, int i, int s)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int m = i;//max element
    if (l < s && a[l] > a[m])
    {
        m = l;
    }
    if (r < s && a[r] > a[m])
    {
        m = r;
    }

    if (m != i)
    {
        int temp = a[m];
        a[m] = a[i];
        a[i] = temp;
        max_heapify(a, (i - 1) / 2, s);
    }
}

void print_arr(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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
    for (int i = 0; i < n / 2; i++)
    {
        max_heapify(a, i, n);
    }
    print_arr(a, n);
    return 0;
}
