#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int concat(string &a, string &b)
{
    int len1 = a.length();
    int len2 = b.length();
    if (len1 < len2)
    {
        for (int i = 0; i < len2 - len1; i++)
            a = "0" + a;
    }
    if (len2 < len1)
    {
        for (int i = 0; i < len1 - len2; i++)
            b = "0" + b;
    }
    return a.length();
}

void remove(string &a)
{
    int i = 0;
    while (a[i] == '0')
    {
        i++;
    }
    a = a.substr(i);
}

string addz(string a, int t)
{
    while (t--)
    {
        a += "0";
    }
    return a;
}

bool bigger(string a, string b)
{
    int len1 = a.length();
    int len2 = b.length();

    if(len1 > len2)
        return true;
    if(len2 > len1)
        return false;
    for(int i = 0; i < len1; i++)
    {
        if(a[i] < b[i])
            return false;
        else if(a[i] > b[i])
            return true;
    }

    return true;
}

string difference(string a, string b)
{
    if(!bigger(a, b))
    {
        swap(a, b);
    }

    string ans = "";
    int len2 = b.length();
    int len1 = a.length();
    int diff = len1- len2;
    int carry = 0;
    for(int i = len2-1; i >= 0; i--)
    {
        int num = (a[diff + i]-'0') - (b[i]-'0') - carry;
        if(num < 0)
        {
            carry = 1;
            num += 10;
        }
        else
        {
            carry = 0;
        }

        ans.push_back(num+'0');
    }

    for(int i = diff-1; i >= 0; i--)
    {
        if(a[i] == '0' && carry)
        {
            ans.push_back('9');
            continue;
        }

        int num = (a[i]-'0')-carry;
        if(i > 0 || num > 0)
            ans.push_back(num+'0');
    	carry = 0;
    }
    reverse(ans.begin(), ans.end());
    remove(ans);
    return ans;
}

string add(string a, string b)
{
    string ans = "";

    int len = concat(a, b);
    int carry = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        int num = (a[i] - '0') + (b[i] - '0') + carry;
        ans.push_back(num % 10 + '0');
        carry = num / 10;
    }

    if (carry > 0)
        ans.push_back(carry + '0');
    reverse(ans.begin(), ans.end());
    remove(ans);
    return ans;
}

string multiply(string a, string b)
{
    string ans;

    int i;
    remove(a);
    remove(b);
    int len1 = a.length();
    int len2 = b.length();
    for (i = len2 - 1; i >= 0; i--)
    {
        int carry = 0;
        string temp = "";
        int j;
        for (j = len1 - 1; j >= 0; j--)
        {
            int num = (b[i] - '0') * (a[j] - '0') + carry;
            temp.push_back(num % 10 + '0');
            carry = num / 10;
        }
        if (carry > 0)
            temp += to_string(carry);
        reverse(temp.begin(), temp.end());
        remove(temp);
        temp = addz(temp, len2 - i - 1);
        ans = add(ans, temp);
    }
    remove(ans);
    return ans;
}

string karatsuba(string str1, string str2)
{

    if(!bigger(str1, str2))
        swap(str1, str2);
    int len = str1.length();
    int half = len/2;
    string a, b, c, d;
    for(int i = 0; i < half; i++)
    {
        a.push_back(str1[i]);
        c.push_back(str2[i]);
    }

    for(int i = half; i < len; i++)
    {
        b.push_back(str1[i]);
        d.push_back(str2[i]);
    }

    string ac = multiply(a, c);
    string bd = multiply(b, d);
    string temp1 = multiply(add(a, b), add(c, d));
    string temp2 = add(ac, bd);
    string mid = difference(temp1, temp2);
    while(len--)
    {
        ac += "0";
    }
    while(half--)
    {
        mid += "0";
    }
    
    string ans = add(ac, mid);
    ans = add(ans, bd);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string num1, num2;
        cin >> num1 >> num2;

        if (num1[0] == '0' || num2[0] == '0')
        {
            cout << 0 << endl;
            continue;
        }

        int len = concat(num1, num2);
        string ans = karatsuba(num1, num2);
        cout << ans << endl;
    }
    return 0;
}