#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

class TrieNode {
    TrieNode* arr[10];
    bool isTreminal;
    TrieNode() {
        for(int i = 0; i < 10; i++)
        {
            arr[i] = NULL;
        }
        this->isTreminal = false;
    }
};

bool insert(string num, TrieNode* root, bool& flag)
{
    
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string num;
        bool flag = true;

        for(int i = 0; i < n; i++)
        {
            cin >> num;
            
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}