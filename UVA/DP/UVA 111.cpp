#include <bits/stdc++.h>
#define ii pair <int, int>
using namespace std;

ii a[21];
ii b[21];
int f[21][21];
int n;

main(){
	//freopen("in.inp","r",stdin);
	
	cin >> n;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a, a+n+1);
	while (cin >> b[1].first)
	{
		b[1].second = 1;
		for (int i = 2; i <= n; i++) 
		{
			cin >> b[i].first;
			b[i].second = i;
		}
		sort (b, b+n+1);
		for (int i = 0; i <= 20; i++)
			for (int j = 0; j <= 20; j++) f[i][j] = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (a[i].second == b[j].second) 
				{
					f[i][j] = f[i-1][j-1] + 1, f[i][j];
				}
				else 
				{
					f[i][j] = max(f[i-1][j], f[i][j-1]);
				}
		cout << f[n][n] << endl;
	}
}
