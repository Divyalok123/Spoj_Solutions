#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
#include <iomanip>
#include <stack>
using namespace std;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define uint unsigned int
#define endl "\n"

stack<int> mystack;

int main(){
    fast;
    int n;
    cin >> n;
    while(n != 0)
    {
        int* arr = new int[n];
        for(int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }

        int i = 1;
        for(int j = 0; j < n; j++)
        {
            if(arr[j] == i)
            {
                i++;
                while(!mystack.empty() && mystack.top() == i)
                {
                    i++;
                    mystack.pop();
                }
            }
            else
            {
                mystack.push(arr[j]);
            }
            
        }

        if(mystack.empty())
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
            while(!mystack.empty())
            {
                mystack.pop();
            }
        }
        delete[] arr;
        cin >> n;
    }
    return 0;
}