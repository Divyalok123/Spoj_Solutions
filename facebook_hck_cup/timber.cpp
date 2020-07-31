#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;
#define endl '\n'
#define pll pair<long long, long long>
#define mp make_pair
#define ll long long
#define ff first
#define ss second

vector<pll> v;

ll solve(int n) {
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n, maxi;
    ll p, h;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> n;
        v.resize(n);
        maxi = INT_MIN;
        for(int j = 0; j < n; j++) {
            cin >> p >> h;
            v[j] = mp(p, h);
            if(h > maxi) maxi = h;
        }

        sort(v.begin(), v.end());

        for(int i = 0; i < n; i++)
            cout << v[i].ff << " " << v[i].ss << endl;
        // cout << "Case #" << i << ": " << solve(n) << endl; 

        v.clear();
    }

    return 0;
}