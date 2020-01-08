#include <bits/stdc++.h>
using namespace std;

main(){
	//freopen("in.inp","r",stdin);
	int test;
	cin >> test;
	while (test--)
	{
		int n, p;
		cin >> n;
		cin >> p;
		int a[p];
		int ans = 0;
		for (int i = 0; i < p; i++) cin >> a[i];
		for (int i = 1; i <= n; i++)
			{
				if (i % 7 == 6 || i % 7 == 0) continue;
				bool ok = false;
				for (int j = 0; j < p; j++)
				{
					if (i % a[j] == 0) 
					{
						ok = true;
						break;
					}
				}
				ans += ok;
			}
		cout << ans << endl;
	}
}
