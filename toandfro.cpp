#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define ll long long 
#define l long
#define uint unsigned int
#define endl "\n"

void solve(int n, string s)
{
    string ans = "";
    int div = 2*n;
    int len = s.length();

    for(int i = 0; i < div/2; i++)
    {
        for(int j = i; j < len; j+= div)
        {
            ans += s[j];
            if(j+div-2*i-1 < len) ans += s[j+div-2*i-1];
        }
    }  

    cout << ans << endl;
}

int main ()
{
    fast;
    int n;
    cin >> n;
    while(n)
    {
        string s;
        cin >> s;
        solve(n, s);
        cin >> n;
    }
    return 0;
}