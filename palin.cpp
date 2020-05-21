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

// int arr[1000005];

string clearzeroes(string s)
{
    int i = 0;
    while(i < s.length() && s[i] == '0')
    {
        i++;
    }
    return s.substr(i);
}

bool checkAllNine(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != '9')
        {
            return false;
        }
    }
    return true;
}

void findNext(string& arr, int n)
{
    int left = n/2-1;
    int right = (n+1)/2;

    int mid = n/2;
    bool flag = false;
    while(left >= 0 && arr[left] == arr[right])
    {
        left--;
        right++;
    }

    if(left < 0 || arr[left] < arr[right])
        flag = true;
    
    while(left >= 0)
    {
        arr[right] = arr[left];
        left--;
        right++;
    }

    if(flag == true)
    {
        int carry = 1;
        if(n%2)
        {
            int num = (int)(arr[mid]-'0') + carry;
            carry = num/10;
            arr[mid] = (num%10 + '0');
        }

        left = n/2-1;
        right = (n+1)/2;

        while(left >= 0)
        {
            int num = (int)(arr[left]-'0') + carry;
            carry = num/10;
            arr[left] = (num%10 +'0');
            arr[right] = arr[left];
            left--;
            right++;
        }
    }

    // for(int i = 0; i < n; i++)
    // {
    //     cout << arr[i];
    // }
    // cout << endl;
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
        s = clearzeroes(s);

        if(checkAllNine(s))
        {
            string ans = "";
            ans.push_back('1');
            for(int i = 0; i < s.length()-1; i++)
            {
                ans.push_back('0');
            }
            ans.push_back('1');
            cout << ans << endl;
            continue;
        }

        // memset(arr, 0, sizeof(arr));
        // for(int i = 0; i < s.length(); i++)
        // {
        //     arr[i] = s[i] - '0';
        // }

        findNext(s, s.length());
        cout << s << endl;
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