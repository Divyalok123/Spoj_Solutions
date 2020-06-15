#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, int> store;
string arr[8] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        int n; 
        cin >> n; 
        cin >> s;

        for(int i = 0; i < 38; i++)
        {
            store[s.substr(i, 3)]++;
        }

        cout << n << " ";
        for(int i = 0; i < 8; i++)
        {
            cout << store[arr[i]] << " ";
        }
        cout << endl;
        store.clear();
    }
    return 0;
}