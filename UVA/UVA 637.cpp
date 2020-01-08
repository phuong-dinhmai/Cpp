#include <bits/stdc++.h>
using namespace std;

int test;
char s[130];
stack <char> ans;

bool kt(){
	while (!ans.empty()) ans.pop();
	for (int i=0; i<strlen(s); i++)
	{
		if ((s[i] == '(') || (s[i] == ')') || (s[i] == '[') || (s[i] == ']' ))
		{
			if (s[i] == '(' || s[i] == '[' ) ans.push(s[i]);
			else 
			{
				if (!ans.empty()) 
				{
					if (s[i] == ')' && ans.top() == '(') ans.pop();
					else if (s[i] == ']' && ans.top() == '[') ans.pop();
					else 
					{
						return false;
					}	
				}
			else return false;
			}
		}
	}
	if (ans.empty()) return true; else return false;
}

main(){
	freopen ("in.inp","r",stdin);
	scanf("%d\n",&test);
	//fflush(stdin);
	for (int k=0; k<test; k++)
	{
		gets(s);
		if (kt()) cout << "Yes" << endl; else cout << "No" << endl;
	}
}
