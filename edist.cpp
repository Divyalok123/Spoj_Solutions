#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <stdexcept>
#include <stack>
#include <queue>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define uint unsigned int
#define endl "\n"
#define setbits(x) __builtin_popcountll(x) // returns no. of set bits (for GCC compiler.. Much faster) 
typedef priority_queue<int> maxheap;
typedef priority_queue<int, vector<int>, greater<int>> minheap; 

int dp[2001][2001];
char a[2001], b[2001];
int solve(char* a, char* b)
{
    int n = strlen(a);
    int m = strlen(b);

    if(min(n, m) == 0) return max(n, m);

    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for(int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[n-i] == b[m-j])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
            }
            
        }
    }

    return dp[n][m];
}

int main() {
    fast;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%s", a);
        scanf("%s", b);
        memset(dp, -1, sizeof(dp));
        int ans = solve(a, b);
        printf("%d\n", ans);
        return 0;

    }
    return 0;
}

