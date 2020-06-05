#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;
#define ll long long
#define high 10000009
//Method 1: stack (already done)

int dp[2005][2005];
//Method 2: memo (TLE)
// int solve(int i, int count, string s, int len)
// {
//     if(count < 0)
//     {
//         return high;
//     }

//     if(i == len) {if(count == 0) return 0; else return high;}

//     if(dp[i][count] != -1) return dp[i][count];

//     if(s[i] == '{')
//     {
//         dp[i][count] = min(1 + solve(i+1, count-1, s, len), solve(i+1, count+1, s, len));
//     }
//     else
//         dp[i][count] = min(1 + solve(i+1, count+1, s, len), solve(i+1, count-1, s, len));

//     return dp[i][count];
// }

//Method 3: DP
void solve(string s)
{
    int size = s.length();
    memset(dp, 1e6, sizeof(dp));

    dp[0][0] = 0;
    for (int i = 1; i <= size; i++)
    {
        for (int j = 0; j <= size; j++)
        {
            if (s[i - 1] == '{')
            {
                dp[i][j] = min(j == 0 ? INT_MAX : dp[i - 1][j - 1], 1 + dp[i - 1][j + 1]);
            }
            else
            {
                dp[i][j] = min(j == 0 ? INT_MAX : 1 + dp[i - 1][j - 1], dp[i - 1][j + 1]);
            }
        }
    }

    cout << dp[size][0] << endl;
}

//Method 4: simple iteration
// void solve(string s)
// {
//     int size = s.length();

//     int open = 0;
//     int closed = 0;
//     int i = 0;
//     while(i < size)
//     {
//         if(s[i] == '}')
//         {
//             if(open == 0) {open = 1; closed++;}
//             else open--;
//         }
//         else
//         {
//             open++;
//         }
//         i++;
//     }

//     cout << closed + open/2 << endl;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int c = 1;
    while (s[0] != '-')
    {
        cout << c << ". ";
        // memset(dp, -1, sizeof(dp));
        // int ans = solve(0, 0, s, s.length());
        // cout << ans << endl;
        solve(s);
        c++;
        cin >> s;
    }

    return 0;
}
