#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    sort(num.begin(), num.end());
    for (int i = 0; i < n; i++)
    {
        cout << num[i] << " ";
    }
    return 0;
}