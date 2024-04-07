#include <bits/stdc++.h>
using namespace std;

int Maxx(vector<int> &num)
{
    int n = num.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (num[i] > num[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    vector<int> nu;
    int a;
    cin >> a;
    while (a--)
    {
        int t = 0;
        cin >> t;
        nu.push_back(t);
    }
    int b = Maxx(nu);
    cout << b;
    return 0;
}
