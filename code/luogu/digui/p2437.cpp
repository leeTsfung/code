#include <bits/stdc++.h>
using namespace std;

int n, m, len = 1;
int f[1005][1005];
void Plus(int x)
{
    for (int i = 1; i <= len; i++)
        f[x][i] = f[x - 1][i] + f[x - 2][i];
    for (int i = 1; i <= len; i++)
    {
        if (f[x][i] > 9)
        {
            f[x][i + 1] += f[x][i] / 10; // 有多少个十位数
            f[x][i] %= 10;               // 只留个位数
        }
    }
    if (f[x][len + 1])
        len++;
}
int main()
{
    cin >> m >> n;
    f[1][1] = 1;
    f[2][1] = 2;
    for (int i = 3; i <= n - m; i++)
        Plus(i);
    for (int i = len; i; i--)
        cout << f[n - m][i];
    return 0;
}