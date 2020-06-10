#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
#define ll long long

ll pi(ll n)
{

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    //nth prime is found in this range
    ll l = n*log(n) + n*(log(log(n))-.6);
    ll u = n*log(n) + n*(log(log(n))+.9);

    cout << "l: " << l << endl;
    cout << "u: " << u << endl;

    ll ans = -1;
    while(l < u)
    {
        ll mid = l + (u-l)/2;
        if(pi(mid) < n)
        {
            l = mid+1;
        }
        else
        {
            ans = mid;
            u = mid-1;
        }
    }

    cout << "Ans: " << ans << endl;

    return 0;
}