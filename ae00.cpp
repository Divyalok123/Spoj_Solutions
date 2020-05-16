#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define ll long long 
#define uint unsigned int
#define ulli unsigned long long int
#define endl "\n"

ll solve(int n)
{
    if(n == 1 || n == 2 || n == 3) return n;
    ll ans = n;
    
    int i;
    for(int i = 2; i*i <= n; i++)
    {
        ans += n/i-(i-1);
    }

    return ans;
}

int main() {
    fast
    int n;
    cin >> n;
    ll ans = solve(n);
    cout << ans;
    return 0;
}
//46884