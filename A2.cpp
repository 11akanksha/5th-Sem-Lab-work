#include <iostream>
using namespace std;

int main()
{
    int n, m = 0;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > m)
            m = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] == m)
        {
            a[i] = -1;
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                a[i] = a[j];
                break;
            }
        }
    }
    a[n - 1] = -1;
    //display the results:
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    delete[] a;
    return 0;
}