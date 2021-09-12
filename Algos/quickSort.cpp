#include <iostream>
using namespace std;

int *a = new int[100];

int partition(int l, int r)
{
    int piv = a[l];
    int i = l;
    int j = r;
    while (i < j)
    {
        do
        {
            i++;
        } while (a[i] <= piv);

        do
        {
            j--;
        } while (a[j] > piv);

        if (i < j)
        {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    int t = a[l];
    a[l] = a[j];
    a[j] = t;
    return j;
}

void quickSort(int l, int h)
{
    if (l < h)
    {
        int pivot = partition(l, h);
        quickSort(l, pivot);
        quickSort(pivot + 1, h);
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quickSort(0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    return 0;
}