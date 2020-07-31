#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string in, out;

bool y(char c) { return c == 'Y'; }

void solve(int n)
{
    vector<vector<char>> v(n+1, vector<char>(n+1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                v[j][i] = 'Y';
            else if (j > i)
            {
                if (y(out[i]))
                {
                    if (!y(in[j]))
                    {
                        v[i][j] = 'N';
                        continue;
                    }
                    if (j - i == 1)
                        v[i][j] = 'Y';
                    else
                    {
                        if (y(v[i][j - 1]) && y(out[j - 1]))
                            v[i][j] = 'Y';
                        else
                            v[i][j] = 'N';
                    }
                }
                else
                    v[i][j] = 'N';
            } else {
                if (y(out[i]))
                {
                    if (!y(in[j]))
                    {
                        v[i][j] = 'N';
                        continue;
                    }
                    if (i - j == 1)
                        v[i][j] = 'Y';
                    else
                    {
                        if (y(v[i-1][j]) && y(in[i - 1]))
                            v[i][j] = 'Y';
                        else
                            v[i][j] = 'N';
                    }
                }
                else
                    v[i][j] = 'N';
            }
        }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cout << v[i][j];
        cout << endl;
    }
}

int main()
{
    int t, n;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        cin >> n;
        cin >> in;
        cin >> out;

        cout << "Case #" << i << ":" << endl;
        solve(n);
    }
    return 0;
}