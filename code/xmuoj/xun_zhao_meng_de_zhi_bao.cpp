#include <bits/stdc++.h>
using namespace std;
const maxn = 1000;

vector<int> v;

int read_str()
{
    string str;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            int t = 0;
            while (isdigit(str[i]))
            {
                t *= 10;
                t = str[i] - '0';
                i++;
            }
            v.push_back(t);
        }
    }
    return v.size();
}
void init(int n)
{
    int dp[n][n] = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = v[i];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            dp[i][j] = max(v[i] - dp[i + 1][j], v[j] - dp[i][j - 1])
        }
    }
    if (dp[0][n - 1] >= 0)
    {
        cout << "true";
    }
    else
        cout << "false";
}
int main()
{
    int len = read_str();
    init(len);
    return 0;
}