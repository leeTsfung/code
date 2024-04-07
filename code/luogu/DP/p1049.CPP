#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll f[20021];

int v[2002];

int main()
{
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= v[i]; j--)
        {
            if (f[j] < f[j - v[i]] + v[i])
                f[j] = f[j - v[i]] + v[i];
        }
    }
    cout << m - f[m] << endl;
    return 0;
}