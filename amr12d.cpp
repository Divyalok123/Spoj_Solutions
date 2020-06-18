#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;

        bool isPalin = true;

        int i = 0;
        int j = s.length()-1;
        while(i < j)
        {
            if(s[i] != s[j])
            {
                isPalin = false;
                break;
            }
            i++;
            j--;
        }

        if(isPalin) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}