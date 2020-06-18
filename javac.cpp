#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string e = "Error!";
    string s;
    while (cin >> s)
    {
        int length = s.length();

        if (isupper(s[0]) || !isalpha(s[0]) || !isalpha(s[length - 1]))
        {
            cout << e << endl;
            continue;
        }

        bool isc = false;
        bool isj = false;
        bool flag = false;
        for (int i = 0; i < length; i++)
        {
            if (i < length - 1 && !isalpha(s[i]) && !isalpha(s[i + 1]))
            {
                flag = true;
                break;
            }
            if (isupper(s[i]))
                isj = true;
            if (!isalpha(s[i]))
                isc = true;
        }

        if((isc && isj) || flag)
        {
            cout << e << endl;
            continue;
        }

        if (!isc && !isj)
        {
            cout << s << endl;
            continue;
        }

        if (isc)
        {
            for (int i = 0; i < length; i++)
            {
                if(!isalpha(s[i]))
                {
                    s.erase(i, 1);
                    s[i] = toupper(s[i]);
                    length--;
                }
            }
        }

        if(isj)
        {
            for(int i = 0; i < length; i++)
            {
                if(isupper(s[i]))
                {
                    s[i] = tolower(s[i]);
                    s.insert(i, "_");
                    length++;
                }
            }
        }

        cout << s << endl;
    }
    return 0;
}