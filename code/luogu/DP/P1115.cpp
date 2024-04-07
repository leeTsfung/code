#include <bits/stdc++.h>
using namespace std;
int a[200002], dp[2000002];
int main()
{
    int n;
    int ans = -20000000;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            dp[i] = a[i];
        else
            dp[i] = max(a[i], dp[i - 1] + a[i]);
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}