#include <iostream>
using namespace std;

int non_zero(int a[4][4])
{
    int s = 16;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (a[i][j] == 0)
            {
                s--;
            }
        }
    }
    return s;
}

int sum_above_diag(int a[4][4])
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (j > i)
            {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

int sum_below_diag(int a[4][4])
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i > j)
            {
                sum += a[i][j];
            }
        }
    }
    return sum;
}

int prod_diag(int a[4][4])
{
    int p = 1;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i == j)
            {
                p *= a[i][j];
            }
        }
    }
    return p;
}

int main()
{
    int a[4][4] = {{1, 2, 3, 4}, {5, 6, 0, 8}, {0, 10, 11, 12}, {13, 0, 15, 16}};
    cout << "Non zero: " << non_zero(a) << endl;
    cout << "sum above diagonal: " << sum_above_diag(a) << endl;
    cout << "sum below diagonal: " << sum_below_diag(a) << endl;
    cout << "product of diagonal: " << prod_diag(a) << endl;
    return 0;
}