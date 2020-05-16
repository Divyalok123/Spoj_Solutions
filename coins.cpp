#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define ll long long int
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define endl "\n"
#include <unordered_map>

unordered_map<long long, long long> mymap;

long long solve(long long n)
{
    if (n <= 1)
    {
        return n;
    }

    if (mymap.find(n) != mymap.end())
        return mymap[n];
    long long val = solve(n / 2) + solve(n / 3) + solve(n / 4);
    mymap[n] = max(n, val);
    return mymap[n];
}

int main()
{
    fast 
    long long t;
    while (cin >> t)
    {
        long long res = solve(t);
        cout << res << "\n";
    }
    return 0;
}
