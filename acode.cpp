#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define ll long long
#define l long
#define uint unsigned int
#define endl "\n"

ll arr[5005];

ll solve(string s)
{
    if(s.length() == 0)
        return -1;

    memset(arr, 0, sizeof(arr));

    arr[0] = 1;
    if(s[0] > '2' && s[1] == '0') return 0;
    else if(s[1] == '0' || (s[0] == '2' && s[1] > '6') || s[0] > '2') arr[1] = 1;
    else arr[1] = 2;

    for(int i = 2; i < s.length(); i++)
    {
        if(s[i] == '0' && s[i-1] > '2') return 0;
        else if(s[i] == '0' && s[i-2] == '0') arr[i] = arr[i-2];
        else if(s[i] == '0') arr[i] = arr[i-1]-1;
        else if(s[i-1] > '2' || (s[i-1] == '2' && s[i] > '6')) arr[i] = arr[i-1];
        else if(s[i-1] == '0') arr[i] = arr[i-2];
        else arr[i] = arr[i-1] + arr[i-2];
    } 

    return arr[s.length()-1];
}


int main()
{
    fast
    string s;
    cin >> s;
    while (s != "0")
    {
        ll ans = solve(s);
        cout << ans << endl;
        cin >> s;
    }
    return 0;
}


// 1111 - 5
// 25144 - 4
// 2262 - 3
// 22621 - 6
// 226210 - 3
// 2203 - 1
// 2020 - 1
// 2022 - 2
// 136517 - 4
// 17221->6
// 172210->4
// 1722101->4
// 17221012->8
// 34->1
// 23->2
// 1017->2
/*
1013
211003
100
21103
101230
0
output
2
0
0
2
0
*/