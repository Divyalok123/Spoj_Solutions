#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

class TrieNode {
public:
    TrieNode* arr[10];
    bool isTerminal;
    TrieNode() {
        for(int i = 0; i < 10; i++)
        {
            arr[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insert(TrieNode* root, string key, bool& flag)
{
    TrieNode* temp = root;
    bool check = false;
    for(int i = 0; i < key.length(); i++)
    {
        int ind = key[i]-'0';
        if(temp->isTerminal) flag = false;
        if(temp->arr[ind] == NULL)
        {
            check = true;
            TrieNode* newn = new TrieNode();
            temp->arr[ind] = newn;
        }
        temp = temp->arr[ind];
    }
    if(!check) flag = false;
    temp->isTerminal = true;
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
        TrieNode* newnode = new TrieNode();
        for(int i = 0; i < n; i++)
        {
            cin >> num;
            insert(newnode, num, flag);
        }

        if(flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}