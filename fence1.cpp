#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define pi 3.14159265358979323846
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int l;
    cin >> l;
    while(l)
    {
        cout << fixed << setprecision(2) << (l*l)/(pi*2) << endl;
        cin >> l;
    }

    return 0;
}
