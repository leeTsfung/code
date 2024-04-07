#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll s[30][30][30] = {0};

ll w(int a, int b, int c)
{
    if (a < 0 || b < 0 || c < 0)
        return 1;
    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    if (a < b && b < c)
    {
        if (s[a][b][c - 1] == 0)
        {
            s[a][b][c - 1] == w(a, b, c - 1);
        }
        if (s[a][b - 1][c - 1] == 0)
        {
            s[a][b - 1][c - 1] = w(a, b - 1, c - 1);
        }

        if (s[a][b - 1][c] == 0)
        {
            s[a][b - 1][c] = w(a, b - 1, c);
        }
        s[a][b][c] = s[a][b][c - 1] + s[a][b - 1][c - 1] - s[a][b - 1][c];
    }
    else
    {
        if (s[a - 1][b][c] == 0)
        {
            s[a - 1][b][c] = w(a - 1, b, c);
        }

        if (s[a - 1][b - 1][c] == 0)
            s[a - 1][b - 1][c] = w(a - 1, b - 1, c);
        if (s[a - 1][b][c - 1] == 0)
            s[a - 1][b][c - 1] = w(a - 1, b, c - 1);
        if (s[a - 1][b - 1][c - 1] == 0)
            s[a - 1][b - 1][c - 1] = w(a - 1, b - 1, c - 1);
        s[a][b][c] = s[a - 1][b][c] + s[a - 1][b - 1][c] + s[a - 1][b][c - 1] - s[a - 1][b - 1][c - 1];
    }
    return s[a][b][c];
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    ll re = w(a, b, c);
    cout << re;
    return 0;
}
