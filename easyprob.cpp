#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int arr[7] = {137, 1315, 73, 136, 255, 1384, 16385};

void solve(int n)
{
    if(n == 0) return;
    else if(n == 1)
        { cout << "2(0)"; return; }
    else if(n == 2)
        { cout << "2"; return; }
    else if(n == 3)
        { cout << "2+2(0)"; return; }
    else if(n == 4)
        { cout << "2(2)"; return;}

    int logval = log2(n);
    int val = pow(2, logval);

    cout << "2(";
    solve(logval);
    cout << ")";

    if(n-val > 0) 
    {
        cout << "+"; 
        solve(n-val);
    }

}

int main() {
    
    for(int i = 0; i < 7; i++)
    {
        cout << arr[i] << "=";
        solve(arr[i]);
        cout << endl;
    }
    return 0;
}

/*
137=2(2(2)+2+2(0))+2(2+2(0))+2(0)
1315=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2(0))+2+2(0)
73=2(2(2)+2)+2(2+2(0))+2(0)
136=2(2(2)+2+2(0))+2(2+2(0))
255=2(2(2)+2+2(0))+2(2(2)+2)+2(2(2)+2(0))+2(2(2))+2(2+2(0))+2(2)+2+2(0)
1384=2(2(2+2(0))+2)+2(2(2+2(0)))+2(2(2)+2)+2(2(2)+2(0))+2(2+2(0))
16385=2(2(2+2(0))+2(2)+2)+2(0)
*/