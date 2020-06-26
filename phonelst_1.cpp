#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> mapp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string no = "NO", yes = "YES";
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string num;
        vector<string> s;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            s.push_back(num);
        }

        sort(s.begin(), s.end());

        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            num = s[i];
            string str = "";
            for (int i = 0; i < num.size(); i++)
            {
                str.push_back(num[i]);
                if (mapp[str])
                    flag = true;
            }
            mapp[num] = true;
        }

        if (flag)
            cout << no << endl;
        else
            cout << yes << endl;
        mapp.clear();
    }

    return 0;
}