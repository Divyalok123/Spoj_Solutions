#include <iostream>
using namespace std;
#define ll long long
 
void solve(int m, int n)
{
 
	//flag represents no prime
	for(int i = m; i <= n; i++)
	{
		bool flag = false;
 
		if(i == 1)
			flag = true;
 
		if(i%2 == 0)
			flag = true;
 
		if(i == 2)
			flag = false;
 
 
		for(int j = 3; j*j <= i; j+=2)
		{
 
			if(i%j == 0)
			{
				flag = true;
				break;
			}
		}
 
		if(!flag)
			cout << i << "\n";
	}
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	int t;
	cin >> t;
	while(t--)
	{
		int m, n;
		cin >> m >> n;
 
		solve(m, n);
		cout << "\n";
	}
 
}