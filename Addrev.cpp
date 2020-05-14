#include <iostream>
#include <algorithm>
using namespace std;

long long reverser(long long num)
{
    int length = 0;
    int x = num;
    while(x)
    {
        x /= 10;
        length++;
    }
    // cout << length << endl;
	long long ans = 0;
	int i = 0;
	while(num)
	{
		ans += (num%10 * pow(10, length - i-1));
		num /= 10;
		i++;
	}
	
	return ans;
}

int main() {
	// your code goes here
	int t;
	cin >> t;
	while(t--)
	{
		long long n1, n2;
		cin >> n1 >> n2;
		
		n1 = reverser(n1);
// 		cout << n1 << endl;
		n2 = reverser(n2);
// 		cout << n2 << endl;
		
		long long finalans = n1 + n2;
		finalans = reverser(finalans);
		cout << finalans << "\n";
	}
	return 0;
}