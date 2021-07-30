#include <iostream>
using namespace std;

bool appr1(int *a, int n)
{
    int k;
    for (int i = 0; i < n; i++)
    {
        k = 0;
        for (int j = i; j < n; j++)
        {
            if (a[i] == a[j])
            {
                k++;
            }
        }
        if (k > n / 2)
        {
            return true;
        }
    }
    return false;
}

bool appr2(int *f, int n, int l)
{
    for (int i = 0; i <= n; i++)
    {
        if (f[i] > l / 2)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m = 0;
    int freq[100] = {0};
    int *a = new int[n];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        freq[a[i]]++;
        if (a[i] > m)
            m = a[i];
    }
    if (appr1(a, n))
    {
        cout << "Array has an element that repeats more than n/2 times\n";
    }
    else
    {
        cout << "There are no elements that occurs more then n/2 times\n";
    }
    if (appr2(freq, m, n))
    {
        cout << "Array has an element that repeats more than n/2 times\n";
    }
    else
    {
        cout << "There are no elements that occurs more then n/2 times\n";
    }

    return 0;
}