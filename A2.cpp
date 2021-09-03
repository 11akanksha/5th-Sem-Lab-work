#include <iostream>
using namespace std;

void min_heap_top_down(int *a, int i, int s)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int m = i;
    if (l < s && a[l] < a[m])
    {
        m = l;
    }
    if (r < s && a[r] < a[m])
    {
        m = r;
    }
    if (m != i)
    {
        int t = a[m];
        a[m] = a[i];
        a[i] = t;
        min_heap_top_down(a, (i - 1) / 2, s);
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
    cout << "----Building the min heap----\n";
    int *a = new int[20];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n / 2; i++)
    {
        min_heap_top_down(a, i, n);
    }
    print_arr(a, n);
    cout << "----Inserting a new element----\n";
    int e;
    cout << "Enter a new element : ";
    cin >> e;
    a[n] = e;
    n++;
    if (e > a[((n - 1) - 1) / 2])
    {
        print_arr(a, n);
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            min_heap_top_down(a, i, n);
        }
        print_arr(a, n);
    }
    cout << "----Deleting the root----\n";
    cout << "Element deleted : " << a[0] << endl;
    a[0] = a[n - 1];
    n--;
    if (a[0] < a[1] && a[0] < a[2])
    {
        print_arr(a, n);
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            min_heap_top_down(a, i, n);
        }
        print_arr(a, n);
    }
    delete[] a;
    return 0;
}