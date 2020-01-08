#include <bits/stdc++.h>
using namespace std;

string s,ans,res;
stack <char> path;
int n=0;

void backtrack(string a, string b, string res)
{
	if (n == s.size()*2)
		{
			if (b == ans) 
			{
				cout << res << endl;
			}
			return ;
		}
	else
	{
		if (a.size() > 0 )
		{
			path.push(a[0]);
			n++;
			backtrack (a.substr(1,a.size()-1),b,res+ (n == 1 ?  "i": " i"));
			path.pop();
			n--;
		}
		if (!path.empty() && path.top() == ans[b.size()])
		{
			char x=path.top();
			n ++;
			b += path.top();
			path.pop();
			backtrack(a, b, res+" o");
			path.push(x);
			b.substr(0, b.size()-2);
			n --;
		}
	}
}

main()
{	
	while (cin >> s >> ans)
	{
		n=0;
		cout << "[" << endl;
		while (!path.empty()) path.pop();
		backtrack(s,"","");
		cout << "]" << endl;
	}
}
