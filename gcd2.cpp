#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--)
    {
        int a; string b;
        cin >> a >> b;
        if(a == 0) { cout << b << endl; continue; }
        int ans = 0;
        for(int i = 0; i < b.length(); i++)
            ans = (ans*10 + (b[i] - '0'))%a;
        cout << (int)__gcd(a, ans) << endl; 
    }
}