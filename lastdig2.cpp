#include <iostream>
#include <string>
using namespace std;
#define ll long long
void s(ll a, ll b, ll m)
{
    ll r = 1;
    while(b)
    {
        if(b&1)
        {
            r = (r*a)%m;
        }
        b >>=1;
        a = (a*a)%m;
    }
    cout << r << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--){
        string a; ll b;
        cin >> a >> b;
        ll v = a.back()-'0';
        if(v == 0) {cout << 0 << endl; continue;}
        if(b == 0) {cout << 1 << endl; continue;}
        s(v, b, 10);
    }
}