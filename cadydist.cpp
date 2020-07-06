#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;
    while(n) {
        
        vector<ll> classes(n);
        vector<ll> candies(n);

        for(int i = 0; i < n; i++) {
            cin >> classes[i];
        }

        for(int i = 0; i < n; i++) {
            cin >> candies[i];
        }

        sort(classes.begin(), classes.end(), greater<ll>());
        sort(candies.begin(), candies.end());

        ll ans = 0;

        for(int i = 0; i < n; i++) {
            ans += classes[i]*candies[i];
        }

        cout << ans << endl;
        cin >> n;
    }

    return 0;
}