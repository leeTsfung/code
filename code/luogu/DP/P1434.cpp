#include <cstdio>
#include <algorithm>
#define r(i, a, b) for (int i = a; i <= b; i++)
#define pk putchar(32)
#define ph putchar(10)
using namespace std;
int t, n, m;
struct wyc
{
    int x, y, h;
} f[10001];   // h高度，x横坐标，y纵坐标
int l[10001]; // 每个点的最优解
int ans;      // 最优解
int max(int x, int y) { return x > y ? x : y; }
int min(int x, int y) { return x < y ? x : y; }
short dx[4] = {-1, 0, 1, 0}; // 四个方向扩展
short dy[4] = {0, 1, 0, -1};
void read(int &a) // 输入优化
{
    a = 0;
    int d = 1;
    char c;
    while (c = getchar(), c < '0' || c > '9')
        if (c == '-')
            d = -1;
    a = a * 10 + c - 48;
    while (c = getchar(), c >= '0' && c <= '9')
        a = a * 10 + c - 48;
    a *= d;
}
void write(int x) // 输出优化
{
    if (x < 0)
    {
        x = -x;
        putchar(45);
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + 48);
    return;
}
bool cmp(wyc x, wyc y) { return x.h > y.h; } // 按高度排序
void LRZ()
{
    int b;
    read(b);
    read(m); // 这里用b，是为了方便保存横纵坐标
    r(i, 1, b)
        r(j, 1, m)
    {
        read(f[++n].h);
        f[n].x = i; // 横坐标
        f[n].y = j; // 纵坐标
    }
    sort(f + 1, f + 1 + n, cmp); // 排序
}
bool check(int i, int j) // 看f[i]能否到达f[j]
{
    r(k, 0, 3) if (f[i].x + dx[k] == f[j].x && f[i].y + dy[k] == f[j].y) return true; // 可以到达
    return false;                                                                     // 否则
}
void dp()
{
    r(i, 1, n)
    {
        l[i] = 1; // 每个点的初始长度就是1
        for (int j = i - 1; j > 0; j--)
            if (check(i, j) && f[j].h > f[i].h) // 如果可以到达
                l[i] = max(l[i], l[j] + 1);     // 动态转移
    }
    r(i, 1, n)
        ans = max(ans, l[i]);
    write(ans); // 输出
}
int main()
{
    LRZ();
    dp();
}