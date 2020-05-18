#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define uint unsigned int
#define endl "\n"

string findNext(string s)
{
    int n = s.length();
    int before = n/2-1;
    int after = (n+1)/2;
    while(before > 0)
    {
        
    }
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        string ans = findNext(s);
        cout << ans << endl;        
    }
    return 0;
}

/*
Input :
22
19091919191
1999991
121
100
890
1221
123450000004
0
808
2133
11111111111111111111
11111111111111111111111111111111111111111
1119191991900234245239919234772376189636415308431
99
999999
241342191
374294242
242343242
898
77777
888888
13413515134000000000000000013488097081324

Output :
19092029091
2000002
131
101
898
1331
123450054321
1
818
2222
11111111122111111111
11111111111111111111211111111111111111111
1119191991900234245239920299325424320091991919111
101
1000001
241343142
374303473
242353242
909
77877
889988
13413515134000000000100000000043151531431
*/