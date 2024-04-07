#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int fx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int fy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};

ll f[40][40];
bool c[40][40];

int main()
{
    int bx, by, mx, my;
    cin >> bx >> by >> mx >> my;
    bx += 2;
    by += 2;
    mx += 2;
    my += 2;
    f[2][1] = 1; // 初始化：起始点右边第一个位置
    c[mx][my] = 1;
    for (int i = 1; i <= 8; i++)
    {

        c[mx + fx[i]][my + fy[i]] = 1;
    }

    for (int i = 1; i <= bx; i++)
    {
        for (int j = 2; j <= by; j++)
        {
            if (c[i][j])
                continue;
            f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    }
    printf("%lld\n", f[bx][by]);
    return 0;
}