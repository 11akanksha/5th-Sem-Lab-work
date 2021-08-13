#include <iostream>
using namespace std;

//tc=O(logn)
long power(int a, int n)
{
    if (n == 0)
        return 1;

    if (a == 0)
        return 0;
    if (n % 2 == 0)
        return power(a * a, n / 2);
    else
        return a * power(a * a, n / 2);
}
int main()
{
    int x, y;
    cout << "Enter 2 numbers : " << endl;
    cin >> x >> y;

    cout << power(x, y);
    return 0;
}