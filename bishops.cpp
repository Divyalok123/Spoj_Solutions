#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

string subtract2(string ans)
{
    int size = ans.size();
    int i = size-1;
    
    if(ans[i] == '0')
    {
        while(ans[i] == '0')
        {
            i--;
        }

        ans[i] = ((ans[i]-'0')-1)+'0';
        i++;
        while(i < size-1)
        {
            ans[i] = '9';
            i++;
        }

        ans[size-1] = '8';
    }
    else
    {
        if(ans[i] >= '2')
        {
            ans[i] = ((ans[i]-'0')-2)+'0';
        }
        else
        {
            ans[i] = '1';
            i--;
            while(ans[i] == '0')
            {
                i--;
            }

            ans[i] = ((ans[i]-'0')-1)+'0';
        }
    }
    return ans;
}

void solve(string s)
{
    if(s == "1") {cout << 1 << endl; return;}
    string ans;
    int carry = 0;
    for(int i = s.length()-1; i >= 0; i--)
    {
        int num = (s[i]-'0')*2 + carry;
        carry = num/10;
        ans.push_back(num%10 + '0');
    }

    if(carry != 0) ans.push_back(carry+'0');
    reverse(ans.begin(), ans.end());

    ans = subtract2(ans);
    int i = 0;
    while(ans[i] == '0') i++;
    cout << ans.substr(i) << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);        

    string line;

    while(cin >> line)
    {
        solve(line);
    }

    return 0;
}