#include <bits/stdc++.h>
using namespace std;

main(){
	//freopen("in.inp","r",stdin);
	int n, m ,t;
	while (cin >> n >> m >> t)
	{
		int ans, res;
		bool ok = false;
		for (int i = t; i >= 0; i--)
		{
			if (n > m) swap(n, m);
			int k = i / n;
			for (int j = k; j >= 0; j--)
			{
				if ((i - (j*n)) % m == 0) 
				{
					ok = true;
					ans = j + (i - (j*n)) / m;
					res = i;
					break;
				}
			}
			if (ok) 
			{
				cout << ans;
				if (res != t) cout << " " << t - res << endl; else cout << endl;
				break;
			}
		}
	}
}
