#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

long long solve(int n) {
    if(n == 1) {
        return 10;
    }

    long long dp[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    while(--n) {
        for(int i = 1; i <= 9; i++) {
            dp[i] += dp[i-1];
        }
    }

    return dp[9];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--) {

        int count, n;
        cin >> count >> n;
        cout << count << " " << solve(n) << endl;
    }
    return 0;
}