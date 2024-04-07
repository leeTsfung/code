#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll f[20][20];

ll dfs(int i, int j)
{
    if (f[i][j])
        return f[i][j];

    if (i == 0)
        return 1; // 边界

    if (j > 0)
        f[i][j] += dfs(i, j - 1);
    f[i][j] += dfs(i - 1, j + 1);
    return f[i][j];
}

int main()
{
    cin >> n;
    cout << dfs(n, 0);
    return 0;
}
