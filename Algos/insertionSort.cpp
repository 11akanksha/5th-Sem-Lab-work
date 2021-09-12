#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++)
    {
        int curr = a[i];
        int j = i - 1;
        while (j >= 0 && curr < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = curr;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    return 0;
}