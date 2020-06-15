#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int arr[105];
vector<int> abc;
vector<int> def;

unordered_map<int, int> abc_map;
unordered_map<int, int> def_map;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                int val = arr[i] * arr[j] + arr[k];
                abc.push_back(val);
                abc_map[val]++;
            }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                if(arr[k]!=0)
                {
                    int val = (arr[i] + arr[j]) * arr[k];
                    def.push_back(val);
                    def_map[val]++;
                }
            }

    int count = 0;
    for(auto x: abc_map){
        count += (def_map[x.first]*x.second);
    }

    cout << count << endl;

    return 0;
}