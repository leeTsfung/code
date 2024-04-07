#include <iostream>
#include <vector>
using namespace std;

int c[1000][1000] = {0}, b[1000][1000] = {0};

void maxlen(vector<char> &a, vector<char> &d)
{
    int len1 = a.size();
    int len2 = d.size();

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if (a[i - 1] == d[j - 1])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
                if (c[i][j] == c[i][j - 1])
                {
                    b[i][j] = 3;
                }
                else
                {
                    b[i][j] = 2;
                }
            }
        }
    }
}

void read(int i, int j, vector<char> &a)
{
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 1)
    {
        read(i - 1, j - 1, a);
        cout << a[i - 1]; // Output character from vector 'a'
    }
    else if (b[i][j] == 2)
        read(i - 1, j, a);
    else
        read(i, j - 1, a);
}

int main()
{
    // Example usage
    vector<char> a = {'A', 'B', 'C', 'D', 'E'};
    vector<char> b = {'B', 'D', 'E', 'F'};

    maxlen(a, b);
    read(a.size(), b.size(), a); // Start from the end of vectors a and b
    cout << endl;

    return 0;
}
