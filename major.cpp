#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, int> mapp;

int find_c(vector<int>& v, int size)
{
    int curr = 0, count = 1;
    for(int i = 1; i < size; i++)
    {
        if(v[curr] == v[i])
            count++;
        else
            count--;

        if(count == 0)
        {
            curr = i;
            count = 1;
        }
    }
    return v[curr];
}

bool checker(vector<int>& v, int size, int c)
{
    int count = 0;
    int h = size/2+1;
    for(int i = 0; i < size; i++)
    {
        if(v[i] == c)
            count++;
        if(count == h)
            return true;
    }
    return false;
}

void moore(vector<int>& v, int size)
{
    int cand = find_c(v, size);

    bool check = checker(v, size, cand);
    if(check)
    {
        cout << "YES" << " " << cand << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        int x;
        vector<int> v;
        //using moores voting
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            v.push_back(x);
        }

        moore(v, n);
        
        /*
        int h = n/2+1, x;
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            mapp[x]++;
            if(mapp[x] == h)
            {
                cout << "YES" << " " << x << endl;
                flag = true;
            }
        }
        if(!flag)
            cout << "NO" << endl;
        mapp.clear();
        */
    }
    return 0;
}