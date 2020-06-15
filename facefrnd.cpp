#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;
unordered_map<int, int> mapp;
set<int> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int f, nf, x;
        cin >> f >> nf;
        mapp[f] = 1;
        for(int i = 0; i < nf; i++)
        {
            cin >> x;
            s.insert(x);
        }
    }
    int count = 0;

    for(auto x: s)
    {
        if(mapp[x] != 1)
        {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}