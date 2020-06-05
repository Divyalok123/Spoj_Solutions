#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
int Aarr[12], Darr[12];


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, d;
    cin >> a >> d;
    while(1)
    {
        if(a == 0 && d == 0) break;
        for(int i = 0; i < a; i++) cin >> Aarr[i];
        for(int i = 0; i < d; i++) cin >> Darr[i];

        sort(Aarr, Aarr+a);
        sort(Darr, Darr+d);

        int second_elem = (d >= 2) ? Darr[1] : Darr[0];
        bool flag = false;
        for(int i = 0; i < a; i++)
        {
            if(Aarr[i] < second_elem) { flag = true; break;}
        }
        if(!flag) cout << "N" << endl;
        else cout << "Y" << endl;
        cin >> a >> d;
    }

    return 0;
}