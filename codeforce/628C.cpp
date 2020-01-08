#include <bits/stdc++.h>
using namespace std;

int n, dis;
string s;

main(){
//	freopen("in.inp","r",stdin);
	cin >> n >> dis;
	for (int i = 0; i < n; i++)
	{
		char c, x;
		cin >> c;
		if ('z' - c > c - 'a') x = 'z'; else x = 'a';
		if (abs(x - c) > dis)
		{
			if (x == 'a') x = c - dis; else x = c + dis;
		}
		s += x;
		dis -= (abs(x - c));
	}
	
	if (dis > 0) cout << -1 << endl; else cout << s << endl;
	
}
