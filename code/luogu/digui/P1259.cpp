#include <bits/stdc++.h>
using namespace std;

int n;
char ch[205];
void swap(char &n, char &m)
{
    char t = n;
    n = m;
    m = t;
}
void output()
{
    for (int i = 0; i < 2 * n + 2; i++)
    {
        cout << ch[i];
    }
    cout << endl;
}
void move(int a, int b)
{
    swap(ch[a], ch[b]);
    swap(ch[a + 1], ch[b + 1]);
    output();
}

string out[4] = {"ooo*o**--*", "o--*o**oo*", "o*o*o*--o*", "--o*o*o*o*"};

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        ch[i] = 'o';
    }
    for (int i = n; i < 2 * n; i++)
    {
        ch[i] = '*';
    }
    ch[2 * n] = ch[2 * n + 1] = '-';
    output();
    int len = n;
    while (1)
    {
        move(len - 1, 2 * len);
        len--;
        if (len == 3)
            break;
        move(len, 2 * len);
    }
    string ss;
    for (int i = 0; i < n - 4; i++)
    {
        ss += "o*";
    }
    for (int j = 0; j < 4; j++)
    {
        cout << out[j] << ss << endl;
    }
}