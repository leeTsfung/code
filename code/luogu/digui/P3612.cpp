#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s;

int main()
{
    cin >> s;
    ll n;
    cin >> n;
    ll len = s.size();
    while (len > n)
    {
        ll i = len;
        while (n > i)
            i *= 2; // 算出包含n的最短字符串
        i /= 2;
        n -= (i + 1) if (n == 0) n = i;
    }
    cout << s[n - 1];
    return 0;
}