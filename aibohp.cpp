#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;
#define ll long long
#define ull unsigned long long

//memo
// int memo[4200][4200]; //(correct buts gives TLE)

// int solve(string s, int start, int end)
// {
//     int size = s.length();
//     if(size == 0 ||  size == 1 || start >= end)
//     {
//         return 0;
//     }
//     if(memo[start][end] != -1) return memo[start][end];
//     if(s[start] == s[end])
//     {
//         memo[start][end] = solve(s, start + 1, end-1);
//     }
//     else memo[start][end] = min(solve(s, start + 1, end), solve(s, start, end-1)) + 1;

//     return memo[start][end];
// }

//dp
int dp[6200][6200];
int solve(string s)
{
    int size = s.length();
    if (size == 0 || size == 1)
        return 0;
    cout << "Size: " << size << endl;
    memset(dp, 0, sizeof(dp));

    for (int i = 2; i <= size; i++)
        for (int j = 0; j <= size - i; j++)
        {
            if (s[j] == s[j +i- 1] && i == 2)
                dp[j][j+i-1] = 0;
            if (s[j] == s[j + i- 1])
                dp[j][j+i-1] = dp[j + 1][j + i -2];
            else
                dp[j][j+i-1] = min(dp[j + 1][j+i-1], dp[j][j +i- 2]) + 1;
        }

    return dp[0][size-1];
}

//dp (using LCS)
// int dp[6200][6200];
// int solve(string s)
// {
//     int size = s.length();
//     string prerev = s;
//     reverse(s.begin(), s.end());
//     if(size == 0 || size == 1) return 0;
//     memset(dp, 0, sizeof(dp));

//     int i, j;
//     for(i = 1; i <= size; i++)
//         for(j = 1; j <= size; j++)
//         {
//             if(prerev[i-1] == s[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
//             else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//         }

//     return size - dp[size][size];
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        // memset(memo, -1, sizeof(memo));
        // int ans = solve(s, 0, s.length()-1);

        cout << solve(s) << endl;
    }

    return 0;
}
