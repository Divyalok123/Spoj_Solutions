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
#define l long
#define uint unsigned int
#define endl "\n"

//I'm proud of solving this ques :)

void concatzero(string& a, string& b) //just to make things easier
{
    int lenA = a.length();
    int lenB = b.length();
    if(lenA == lenB) return;
    if(lenA > lenB)
    {
        int n = lenA-lenB;
        reverse(b.begin(), b.end());
        for(int i = 0; i < n; i++)
        {
            b.push_back('0');
        }
        reverse(b.begin(), b.end());
    }
    else
    {
        int n = lenB-lenA;
        reverse(a.begin(), a.end());
        for(int i = 0; i < n; i++)
        {
            a.push_back('0');
        }
        reverse(a.begin(), a.end());
    }
    
}

string sub(string a, string b)
{
    string ans = "";
    concatzero(a, b);
    bool flag = false;
    if(a[0]-'0' < b[0]-'0') //just in case(definitely not necessary in this question)
    {
        flag = true;
        string temp = a;
        a = b;
        b = temp;
    }

    for(int i = a.length()-1; i >= 0; i--)
    {
        int aval = a[i]-'0';
        int bval = b[i]-'0';
        if(aval - bval < 0)
        {
            ans.push_back('0' + (aval-bval+10));
            a[i-1] = '0'+ ((a[i-1]-'0')-1);
        }
        else
        {
            ans.push_back('0' + (aval-bval));
        }
    }    
    if(flag) ans.push_back('-');
    reverse(ans.begin(), ans.end());
    int i = 0;
    while(ans[i] == '0')
    {
        i++;
    }
    ans = ans.substr(i);
    if(ans.empty()) return "0";
    return ans;
}

string div2(string s) //division by 2
{
    int carry = 0;
    string ans = "";
    for(int i = 0; i < s.length(); i++)
    {
        int val = carry*10 + (s[i]-'0');
        ans.push_back(val/2 + '0');
        carry = val%2;
    }
    if(ans[0] == '0') ans = ans.substr(1);
    if(ans.empty()) return "0";
    return ans;
}

string add(string a, string b)
{
    string ans = "";
    concatzero(a, b);
    int carry = 0;
    for(int i = a.length()-1; i >= 0; i--)
    {
        int val = (a[i]-'0') + (b[i]-'0') + carry;
        ans.push_back(val%10 + '0');
        carry = val/10;
    }
    if(carry != 0) ans.push_back(carry + '0');
    reverse(ans.begin(), ans.end());
    if(ans.empty()) return "0";
    return ans;
}

void solve(string both, string more)
{
    string k,  n;
    string addition = add(both, more);
    k = div2(addition);
    n = sub(both, k);
    cout << k << endl << n << endl;
}

int main()
{
    fast;
    for(int i = 0; i < 10; i++)
    {
        string both, more;
        cin >> both >> more;
        solve(both, more);
    }
    return 0;
}