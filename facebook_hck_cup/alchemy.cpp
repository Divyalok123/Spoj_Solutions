#include <iostream>
#include <string>
using namespace std;
string s;
#define endl '\n'

bool solve(int n) {
    int counta = 0, countb = 0;
    for(int i = 0; i < n; i++) {  
        if(s[i] == 'B')
            countb++;
        else counta++;
    }

    return abs(counta-countb) == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;
    for(int i = 1; i <= t; i++)
    {
        cin >> n;
        cin >> s;
        cout << "Case #" << i << ": ";
        if(solve(n)) {
            cout << 'Y' << endl;
        } else cout << 'N' << endl;
    }

    return 0;
}