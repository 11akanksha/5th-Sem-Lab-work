#include <iostream>
using namespace std;

//if n==1 T(n)= O(1)
//else 2T(n/2)+2n.

void func(int n)
{
    if (n == 1)
    {
        cout << n << endl;
        return;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << i << " ";
        }
        cout << endl;

        for (int i = n; i > 0; i--)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "------------------------" << endl;
    }
    func(n / 2);
    func(n / 2);
}

int main()
{
    int n;
    cout << "Value of n:\t";
    cin >> n;
    func(n);
    return 0;
}