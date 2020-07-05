#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        cout << ceil((double)n/2) << endl;
    }
    return 0;
}