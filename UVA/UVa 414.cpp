#include <bits/stdc++.h>
using namespace std;

main(){
	//freopen("in.inp","r",stdin);
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0) break;
		getchar();
		int ans = 0, mx = 0;
		string line, ss;
		int a[n];
		fill(a, a+n, 0);
		for (int i = 0; i < n; i++)
		{
			getline(cin, line);
			stringstream s (line);
			while (s >> ss)
			{
				a[i] += ss.size();
			}
			mx = max(mx, a[i]);
		}
		for (int i = 0; i < n; i++) ans += (mx - a[i]);
		cout << ans << endl;
	}
}
