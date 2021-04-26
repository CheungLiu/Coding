#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;

#include <algorithm>
using namespace std;
vector<double> L;
int n, m;
bool check(double k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += L[i] / k;
    }
    return count >= m;
}
double slove(vector<double> &L)
{
    double l = 0.0, r = L[n - 1] + 1.0;
    while (l < r)
    {
        double k = (l + r) / 2.0;
        if (check(k))
        {
            l = k;
        }
        else
        {
            r = k - 0.001;
        }
    }
    return l;
}
int main()
{

    cin >> n >> m;
    double x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        L.push_back(x);
    }
    sort(L.begin(), L.end());
    double result;
    result = slove(L);
    printf("%.2f", result);
    return 0;
}