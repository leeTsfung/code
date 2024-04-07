#include <bits/stdc++.h>
#define maxn 201
#define fo(x) for (register int i = 1; i <= x; ++i)
using namespace std;
bool rd[maxn][maxn];

int a[maxn], dp[maxn], p[maxn], pos;
void DFS(int x)
{
    if (p[x])
        DFS(p[x]);
    cout << x << " ";
}

int main()
{
    int n, ans = 0;
    cin >> n;
    fo(n)
            cin >>
        a[i];

    fo(n - 1) for (register int j = i + 1; j <= n; j++)
    {
        cin >> rd[i][j];
    }
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = a[i];
        for (int j = i - 1; j > 0; j--)
        {
            if (rd[j][i] && dp[i] < dp[j] + a[i])
            {
                dp[i] = dp[j] + a[i];
                p[i] = j;
            }
        }
        if (ans < dp[i])
        {
            ans = dp[i];
            pos = i;
        }
    }
    DFS(pos);
    cout << endl
         << ans;

    return 0;
}