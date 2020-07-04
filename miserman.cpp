#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 10000009

int memo[102][102];

// int solve(vector<vector<int>>& v, int i, int j, int n, int m) {
//     if(i == n) 
//         return 0;

//     if(memo[i][j] != -1) return memo[i][j];

//     int left = j-1 >= 0 ? solve(v, i+1, j-1, n, m) : MAX;
//     int same = solve(v, i+1, j, n, m);
//     int right = j+1 < n ? solve(v, i+1, j+1, n, m) : MAX;
//     memo[i][j] = v[i][j] + min(left, min(right, same));
//     return memo[i][j];
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> v[i][j];

    // memset(memo, -1, sizeof(memo));

    // int ans = MAX;
    // for(int i = 0; i < m; i++) {
    //     ans = min(ans, solve(v, 0, i, n, m));
    // }

    // cout << ans << endl;

    memset(memo, 0, sizeof(memo));

    for(int i = 0; i < n; i++)
    {
        memo[i][0] = MAX;
        memo[i][n+1] = MAX;
    }

    for(int i = 1; i <= m; i++)
        memo[1][i] = v[0][i-1];
    
    for(int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= m; j++) {
            memo[i][j] = v[i-1][j-1] + min(memo[i-1][j], min(memo[i-1][j-1], memo[i-1][j+1]));
        }
    }

    int minim = MAX;
    for(int i = 1; i <= m; i++)
        minim = min(memo[n][i], minim);
    cout << minim << endl;
    return 0;
}