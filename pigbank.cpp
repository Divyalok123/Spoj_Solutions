#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 1e6
int value[505];
int weight[505];

int solve(int w, int n, int val)
{
    if(w == 0) return val;
    if(w < 0) return MAX;
    if(n == 0) return MAX;
    if(weight[n-1] <= w)
        return min(solve(w-weight[n-1], n, val + value[n-1]), solve(w, n-1, val));
    else
        return solve(w, n-1, val);
}

// void solve(int w, int n)
// {
//     int* dp = new int[w+1];
//     for(int i = 0; i <= w; i++)
//         dp[i] = MAX;
//     dp[0] = 0;

//     for(int i = 1; i <= w; i++)
//         for(int j = 0; j < n; j++)
//         {
//             if(weight[j] <= i && weight[j]!=MAX)
//             {
//                 dp[i] = min(dp[i], dp[i-weight[j]] + value[j]);
//             }
//         }

//     if(dp[w] != MAX)
//         cout << "The minimum amount of money in the piggy-bank is " << dp[w] << "." << endl;
//     else
//         cout << "This is impossible." << endl;

//     delete[] dp;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int e, f;
        cin >> e >> f;

        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            cin >> value[i] >> weight[i];
        }

        int ans = solve(f-e, n, 0);

        if(ans != MAX) cout << "The minimum amount of money in the piggy-bank is " << ans << "." << endl;
        else cout << "This is impossible." << endl;

        // solve(f-e, n);
    }

    return 0;
}