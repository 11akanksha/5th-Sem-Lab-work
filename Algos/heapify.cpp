#include <iostream>
using namespace std;

void max_heapify(int *a, int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int maxi = i;
    if (l < n && a[l] > a[maxi])
    {
        maxi = l;
    }
    if (r < n && a[r] > a[maxi])
    {
        maxi = r;
    }
    if (maxi != i)
    {
        int temp = a[maxi];
        a[maxi] = a[i];
        a[i] = temp;
        max_heapify(a, maxi, n);
    }
}

void min_heapify(int *a, int i, int n)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int mini = i;
    if (l < n && a[l] < a[mini])
    {
        mini = l;
    }
    if (r < n && a[r] < a[mini])
    {
        mini = r;
    }
    if (mini != i)
    {
        int temp = a[mini];
        a[mini] = a[i];
        a[i] = temp;
        min_heapify(a, mini, n);
    }
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
    cout << "Select:\n 0. Max Heapify\n 1. Min Heapify\n";
    bool opt;
    cin >> opt;
    if (opt)
    {
        //Min heapify
        for (int i = n - 1; i >= 0; i--)
        {
            min_heapify(a, i, n);
        }
        print_arr(a, n);
    }
    else
    {
        //max heapify
        for (int i = n - 1; i >= 0; i--)
        {
            max_heapify(a, i, n);
        }
        print_arr(a, n);
    }
    return 0;
}