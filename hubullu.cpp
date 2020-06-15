#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n, a;
        cin >> n >> a;

        if(a == 1) cout << "Pagfloyd wins." << endl;
        else cout << "Airborne wins." << endl;
        
    }
    return 0;
}