#include <iostream>
#include <string.h>
using namespace std;

void build_max_heap(int *a, int i, int s)
{
    int p = (i - 1) / 2;

    if (p >= 0 && a[i] > a[p])
    {
        int t = a[p];
        a[p] = a[i];
        a[i] = t;
        build_max_heap(a, (i - 1) / 2, s);
    }
}

void build_min_heap(int *a, int i, int s)
{

    int p = (i - 1) / 2;

    if (p >= 0 && a[i] < a[p])
    {
        int t = a[p];
        a[p] = a[i];
        a[i] = t;
        build_min_heap(a, (i - 1) / 2, s);
    }
}

string MaxMin(int *h, int n)
{
    string s = "MIN";
    if (h[0] > h[1] && h[0] > h[2])
    {
        s = "MAX"; //heap was a max heap
        for (int i = 0; i < n; i++)
        {
            build_min_heap(h, i, n);
        }
    }
    return s;
}

string MinMax(int *h, int n)
{
    string s = "MAX";
    if (h[0] < h[1] && h[0] < h[2])
    {
        s = "MIN"; //heap was a min heap
        for (int i = 0; i < n; i++)
        {
            build_max_heap(h, i, n);
        }
    }
    return s;
}

void print_arr(int *a, int n)
{
    cout << "The array is : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int *a = new int[20];
    int n;
    cout << "Enter size of heap: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (MaxMin(a, n) == "MAX")
    {
        cout << "Your heap was a max heap.Its now converted to min heap:\n";
        print_arr(a, n);
    }
    else
    {
        MinMax(a, n);
        cout << "Your heap was a min heap.Its now converted to max heap:\n";
        print_arr(a, n);
    }
    delete[] a;
    return 0;
}