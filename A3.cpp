#include <iostream>
using namespace std;

int BS(int *a, int l, int r, int k)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (a[mid] == k)
            return mid;

        if (a[mid] > k)
            return BS(a, l, mid - 1, k);

        return BS(a, mid + 1, r, k);
    }
    return -1;
}

int main()
{
    int n, k;
    cout << "No of elements: ";
    cin >> n;
    cout << "Fill the array: " << endl;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the element you want to search for:" << endl;
    cin >> k;
    int s = 0, e = n - 1;
    int res = BS(a, s, e, k);
    (res == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << res;
    delete[] a;
    return 0;
}