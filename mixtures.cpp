#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstring>
using namespace std;
int arr[105], n;
int mem[105][105];
int sum(int i, int j)
{
    int ans = 0;
    for(int k = i; k <= j; k++)
        ans = (ans + arr[k])%100;

    return ans;
}

//memo
// int solve(int i, int j)
// {
//     if(i== j) return 0;
//     if(mem[i][j] != -1) return mem[i][j];
//     int minans = INT_MAX;
//     for(int k = i; k < j; k++)
//     {
//         minans = min(minans, solve(i, k) + solve(k+1, j) + sum(i, k)*sum(k+1, j));
//     }
//     mem[i][j] = minans;
//     return minans;
// }

//dp
void solve()
{
    memset(mem, 0, sizeof(mem));
    
    for(int i = 2; i <= n; i++)
    {
        for(int j = 0; j < n-i+1; j++)
        {
            int x = j+i-1;
            mem[j][x] = INT_MAX;
            for(int k = j; k < x; k++)
            {
                mem[j][x] = min(mem[j][x], mem[j][k] + mem[k+1][x] + sum(j, k)*sum(k+1, x));
            }
        }
    }
    cout << mem[0][n-1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n)
    {
        // memset(mem, -1, sizeof(mem));
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        if(n == 1) {cout << 0 << endl; continue;}
        if(n == 2) {cout << arr[0]*arr[1] << endl; continue;}
        // int ans = solve(0, n-1);
        // cout << ans << endl;

        solve();
    }

    return 0;
}
