#include <bits/stdc++.h>
using namespace std;

main(){
	//freopen("in.inp","r",stdin);
	int n, test = 0;
	while (cin >> n && n)
	{
		test++;
		int a[n], b[n], diff[n], y[n];
		int year = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> y[i] >> a[i] >> b[i];
			diff[i] = b[i] - a[i];
			year = max(year, y[i]);
		}
		for (; year < 10000; year++)
		{
			int i;
			for (i = 0; i < n; i++)
			{
				if ((year - y[i]) % diff[i] != 0) break;
			}
			if (i == n) break;
		}
		cout << "Case #" << test << ":" << endl;
		if (year == 10000) cout << "Unknown bugs detected." << endl;
		else cout << "The actual year is " << year << "." << endl;
		cout << endl;
	}
}
