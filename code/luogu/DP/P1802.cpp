#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[200002];
int win[1100], lose[1100], use[1100];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> lose[i] >> win[i] >> use[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= use[i]; j--)
        {
            dp[j] = max(dp[j] + lose[i], dp[j - use[i]] + win[i]);
        }
        for (int j = use[i] - 1; j >= 0; j--)
        {
            dp[j] += lose[i];
        }
    }
    cout << 5 * dp[m];
    return 0;
}