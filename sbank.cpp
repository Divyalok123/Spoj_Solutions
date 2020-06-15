#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <map>
#include <cstdio>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, int> mapp;
vector<vector<string>> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            string x;
            string s = "";
            vector<string> temp;
            for(int i = 0; i < 6; i++)
            {
                cin >> x;
                s += x;
                temp.push_back(x);
            }

            if(mapp[s] == 0)
                vec.push_back(temp);

            mapp[s]++;
        }

        sort(vec.begin(), vec.end(), [&](vector<string>& a, vector<string>& b)
        {
            if(a[0] != b[0]) return a[0].compare(b[0]) < 0;
            if(a[1] != b[1]) return a[1].compare(b[1]) < 0;
            if(a[2] != b[2]) return a[2].compare(b[2]) < 0;
            if(a[3] != b[3]) return a[3].compare(b[3]) < 0;
            if(a[4] != b[4]) return a[4].compare(b[4]) < 0;
            return a[5].compare(b[5]) < 0;
        });

        for(int i = 0; i < vec.size(); i++)
        { 
            string s = "";
            for(int j = 0; j < 6; j++)
            {
                s += vec[i][j];
                cout << vec[i][j] << " ";
            }
            cout << mapp[s] << endl;
        }

        mapp.clear();
        vec.clear();
        cout << endl;
    }

    return 0;
}


//Giving wrong answer (although output seems to be correct)
/*
map<string, int> mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    char c[50];
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            fgets(c, 50, stdin);
            mp[(string)c]++;
        }

        map<string, int>::iterator itr = mp.begin();
        while(itr != mp.end())
        {
            cout << itr->first.substr(0, itr->first.size()-1) << " " << itr->second << "\n";
            itr++;
        }

        mp.clear();
        cout << "\n";
    }
    return 0;
}
*/