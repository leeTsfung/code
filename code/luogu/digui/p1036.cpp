#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[25];
long long ans;
bool Is(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

void dfs(int m, int sum, int startx)
{
    if (m == k)
    {
        if (Is(sum))
        {
            ans++;
            return;
        }
    }
    for (int i = startx; i < n; i++)
    {
        dfs(m + 1, sum + a[i], i + 1);
    }
    return;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}
