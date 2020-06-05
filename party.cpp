#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int fun[105], fee[505];
int dp[105][505];
// int val = 0;

void solve(int size, int budget)
{
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= size; i++)
    {
        for(int j = 1; j <= budget; j++)
        {
            if(fee[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(fun[i-1] + dp[i-1][j-fee[i-1]], dp[i-1][j]);
            }
        }
    }

    int val = budget;
    int i = 0;
    int j = budget;
    while(i < j)
    {
        int mid = (j+i)/2;
        if(dp[size][mid] == dp[size][budget]) { val = mid; j = mid;}
        else if(dp[size][mid] < dp[size][budget]) i = mid+1;
        else j = mid-1;
    }

    cout << val << " " << dp[size][budget] << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int budget, n;
    cin >> budget >> n;
    while (budget && n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> fee[i] >> fun[i];
        }

        memset(dp, 0, sizeof(dp));
        solve(n, budget);

        // int ans = solve(0, budget, n);
        // cout << "ans: " << ans << endl;
        cin >> budget >> n;
    }
    return 0;
}