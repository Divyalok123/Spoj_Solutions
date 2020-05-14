#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

char op[5] = {'*', '+', '-', '/', '^'}; //operators

bool isOp(char c) // is it an operator ?
{
	for(int i = 0; i < 5; i++)
	{
		if(op[i] == c)
			return true;
	}
	return false;
}

bool isOpening(char c) //check for opening paranthesis
{
	return c == '(';
}

bool isClosing(char c) //check for closing paranthesis
{
	return c == ')';
}

bool isOperand(char c) //check if it is an operand
{
	return (c-'a' >= 0) && (c-'a' <= 25);
}

void solve(string s)
{
	string ans;
	stack<char> st;
	
	for(int i = 0; i < s.length(); i++)
	{
		if(isOpening(s[i]))
		{
			st.push(s[i]);
		}
		
		else if(isOp(s[i]))
		{
			st.push(s[i]);
		}
		
		else if(isOperand(s[i]))
		{
			ans.push_back(s[i]);
		}
		
		else if(isClosing(s[i]))
		{
			while(!isOpening(st.top()))
			{
				ans.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
	}
	
	cout << ans << endl;
	
}

int main() {
	fast
	int n;
	cin >> n;
	while(n--)
	{
		string s;
		cin >> s;
		
		solve(s);
	}
	return 0;
}