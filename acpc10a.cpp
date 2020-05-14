#include <iostream>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n";

bool AP(int a, int b, int c)
{
    return b-a == c-b;
}

bool GP(int a, int b, int c)
{
    return b/a == c/b;
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    while(a != 0 || b != 0 || c != 0)
    {
        if(AP(a, b, c))
        {
            cout << "AP " << c + (c-b) << endl; 
        }

        else if(GP(a, b, c))
        {
            cout << "GP " << c*(c/b) << endl;
        }
        cin >> a >> b >> c;
    }
}