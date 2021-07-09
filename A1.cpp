#include <iostream>
using namespace std;

void swap_elements(int *a, int *c, int *b, int *d)
{
    int t = *a;
    *a = *c;
    *c = t;

    t = *b;
    *b = *d;
    *d = t;
}

void sort_sr(int (*f)[2], int n)
{
    //sorting of 2nd row in 2d array
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (f[j][1] < f[j + 1][1])
            {
                swap_elements(&f[j][0], &f[j + 1][0], &f[j][1], &f[j + 1][1]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int e[100], f[100][2], b[101] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> e[i];
        b[e[i]]++;
    }
    int j = 0;
    for (int i = 0; i < 101; i++)
    {
        if (b[i] > 0)
        {
            f[j][0] = i;
            f[j][1] = b[i];
            j++;
        }
    }
    sort_sr(f, j);
    for (int i = 0; i < j; i++)
    {
        cout << f[i][0] << " ";
    }
    cout << endl;
    return 0;
}