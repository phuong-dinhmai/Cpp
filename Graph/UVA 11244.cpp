#include <bits/stdc++.h>
using namespace std;

main(){
	int n,m;
	char a[1000][1000];
	
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	while (cin >> n >> m)
	{
		if (n == 0 && m == 0) break;
		int ans = 0;
		for (int i=0; i<1000; i++)
			for (int j=0; j<1000; j++) a[i][j] = '.';
	
		for (int i=1; i<=n ; i++)
			for (int j=1; j<=m; j++) cin >> a[i][j];
		for (int i=1; i<=n; i++)
			for (int j=1; j<=m; j++)
				{
					if (a[i][j] == '*' 
					&& a[i+1][j] != '*' && a[i-1][j] != '*'
					&& a[i+1][j+1] != '*' && a[i+1][j-1] != '*'
					&& a[i-1][j+1] != '*' && a[i-1][j-1] != '*'
					&& a[i][j+1] != '*' && a[i][j-1] != '*') ans++;
				}
		cout << ans << endl;
	}
}
