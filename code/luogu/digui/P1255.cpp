#include <bits/stdc++.h>
using namespace std;

int len = 1, f[5003][5003];

void fb(int k)
{
    int carry = 0; // 初始化进位为0
    for (int i = 1; i <= len; i++)
    {
        f[k][i] = f[k - 1][i] + f[k - 2][i] + carry; // 加上进位
        carry = f[k][i] / 10;                        // 计算新的进位
        f[k][i] %= 10;                               // 取个位数
    }
    while (carry)
    { // 处理最高位进位
        f[k][++len] = carry % 10;
        carry /= 10;
    }
}

int main()
{
    int n;
    cin >> n;
    f[1][1] = 1;
    f[2][1] = 2;
    for (int h = 3; h <= n; h++)
        fb(h);
    for (int j = len; j >= 1; j--)
    {
        printf("%d", f[n][j]);
    }
    return 0;
}
