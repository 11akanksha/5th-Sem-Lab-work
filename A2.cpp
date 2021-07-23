#include <iostream>
#include <math.h>
using namespace std;

//1st approach:
bool prime1(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

//2nd approach:
int prime2(int n)
{
    int c;
    for (int i = 2; i <= n / 2; ++i)
    {
        if (n % i == 0)
        {
            c = 1;
            break;
        }
    }
    return c;
}

// 3rd approach:
int prime3(int n)
{
    int c;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            c = 1;
            break;
        }
    }
    return c;
}

int main()
{
    int n;
    cin >> n;
    cout << "By 1st approach:\t";
    prime1(n) ? cout << "a prime no" << endl : cout << "not a prime" << endl;
    cout << "By 2nd approach:\t";
    prime2(n) == 1 ? cout << "not a prime" << endl : cout << "a prime no" << endl;
    cout << "By 3rd approach:\t";
    prime3(n) == 1 ? cout << "not a prime" << endl : cout << "a prime no" << endl;
    return 0;
}