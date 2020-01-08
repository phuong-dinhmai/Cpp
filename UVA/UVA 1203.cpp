#include <bits/stdc++.h>
#define ii pair <int, int>
using namespace std;

priority_queue <ii, vector <ii>, greater <ii> > ans;
int trace [5000],n;
string s;

main(){
	
	while (cin >> s)
	{
		if (s == "#") break;
		else 
		{
			int x,y;
			cin >> x >> y;
			ans.push( ii (y,x) );
			trace[x]=y;
		}
	}
	cin >> n;
	for (int i=0; i<n; i++) 
	{
		ii v=ans.top();
		ans.pop();
		cout << v.second << endl;
		v.first+=trace[v.second];
		ans.push(v);
	}
}
