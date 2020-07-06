#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    // cin >> t;
    scanf("%d", &t);

    while(t--) {
        ll a, b, c;
        // cin >> a >> b >> c;
        scanf("%lld%lld%lld", &a, &b, &c);

        ll ans = (a*a)-2*(b);
        cout << ans << '\n';
        // printf("%lld\n", ans);    
    }
    return 0;
}