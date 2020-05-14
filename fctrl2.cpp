#include <iostream>
#include <vector>
using namespace std;

void factr(int n)
{
	vector<int> ans;
	ans.push_back(n);
	
	while(--n)
	{
		int carry = 0;
		for(int i = 0; i < ans.size(); i++)
		{
			int val = ans[i]*(n) + carry;
			ans[i] = (val)%10;
			carry = (val)/10;
		}
		if(carry != 0)
		{
			while(carry)
			{
				ans.push_back(carry%10);
				carry /= 10;
			}
		}
	}
	
	for(int j = ans.size()-1; j >= 0; j--)
	{
		cout << ans[j];
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
		int n;
		cin >> n;
		
		factr(n);
		cout << "\n";
	}
	return 0;
}