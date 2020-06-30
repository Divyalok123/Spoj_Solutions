#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,k, num, o, t;
    cin >> n >> k;

    int count = 0;
    while(n--)
    {
        cin >> num;
        //not using % as it's expensive
        o = (int)ceil((double)num/(double)k);
        t = num/k;

        if(o == t)
            count++;
    }

    cout << count << '\n';

    return 0;
}