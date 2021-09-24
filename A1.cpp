#include <iostream>
#include <algorithm>
using namespace std;

class Objects
{
public:
    int wt, p;
    Objects() {}
    Objects(int weight, int profit)
    {
        wt = weight;
        p = profit;
    }
};

bool cmp(Objects o1, Objects o2)
{
    double ratio1 = (double)o1.p / (double)o1.wt;
    double ratio2 = (double)o2.p / (double)o2.wt;
    return ratio1 > ratio2;
}

double Fractional_Knapsack(int m, Objects obj[], int n)
{
    sort(obj, obj + n, cmp);
    int current_wt = 0;
    double total_profit = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (current_wt + obj[i].wt <= m)
        {
            current_wt += obj[i].wt;
            total_profit += obj[i].p;
        }
        else
        {
            int r = m - current_wt;
            total_profit += obj[i].p * ((double)r / (double)obj[i].wt);
            break;
        }
    }
    return total_profit;
}

int main()
{
    int m, n;
    cout << "Enter max size of Knapsack: ";
    cin >> m;
    cout << "Enter no of objects: ";
    cin >> n;
    Objects *o = new Objects[n];
    cout << "Enter weights and profit for each object:" << endl;
    for (int i = 0; i < n; i++)
    {
        int w, pr;
        cin >> w >> pr;
        o[i] = Objects(w, pr);
    }
    cout << "Maximum Profit: " << Fractional_Knapsack(m, o, n);
    delete[] o;
    return 0;
}