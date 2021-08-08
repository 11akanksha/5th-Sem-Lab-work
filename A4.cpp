#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

int main(void)
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
    int result = binarySearch(a, 0, n - 1, k);
    (result == -1) ? cout << "Element is not present in array" : cout << "Element is present at index " << result;
    delete[] a;
    return 0;
}
