#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
#include <iomanip>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define uint unsigned int
#define endl "\n"

void solve(float f)
{
    int i = 1;
    float val = 0.5;
    while(val <= f)
    {
        val += (float)(1/(float)(i+2));
        i++;
    }

    cout << i << " card(s)" << endl;
}

int main() {
    fast;
    float f;
    cin >> f;
    while(f != 0.00)
    {
        solve(f);
        cin >> f;
    }
    return 0;
}