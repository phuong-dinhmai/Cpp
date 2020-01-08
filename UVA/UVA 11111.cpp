#include <bits/stdc++.h>
using namespace std;

stack <long> ans, sum;
int n,a[10000];

bool xuly()
{
	while (!ans.empty()) ans.pop();
	while (!sum.empty()) sum.pop();
	for (int i=0;i<=n;i++)
	{
		if (a[i]<0) 
		{
			ans.push(a[i]);
			sum.push(0);
		}
		else 
		{
			if (ans.empty())  {return false;}
			int x=ans.top();
			ans.pop();
			if (x != -a[i]) {return false;}
			int m=sum.top();
			sum.pop();
			if (m >= a[i]) {return false;}
			if (!sum.empty())	
			{
				long x=sum.top();
				sum.pop();
				sum.push(a[i]+x);
			}	
		}
	}
	if (ans.empty()) return true ; else {return false;} 
}

main(){
	//freopen ("in.inp","r",stdin);
	n=0;
	char c;
	while (scanf ("%d%c",&a[n],&c) != EOF)
	{
		if (c == '\n')
		{
			if (xuly()) cout << ":-) Matrioshka!" << endl; else cout << ":-( Try again." << endl;
			n=0;
		}
		else if (c == ' ') n++;
	}
}
