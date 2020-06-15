#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

vector<pair<int, int>> dat;

void print() {
    cout << endl;
    for(int i = 0; i < dat.size(); i++)
    {
        cout << dat[i].first << " " << dat[i].second << endl;
    }
    cout << endl;
}

void solve(){
    int count = 1;
    int pivot = dat[0].second;
    for(int i = 1; i < dat.size(); i++)
    {
        if(dat[i].first >= pivot)
        {
            count++;
            pivot = dat[i].second;
        }
    }

    cout << count << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int N, m, n;
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            cin >> m >> n;
            dat.push_back({m, n});
        }

        sort(dat.begin(), dat.end(), [&](pair<int, int>& a, pair<int, int>& b){
            return (a.second < b.second) || (a.second == b.second && a.first < b.first);
        });

        // print();
        solve();
        dat.clear();
    }
    return 0;
}
