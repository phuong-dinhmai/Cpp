#include <bits/stdc++.h>
#define maxN 1000005
using namespace std;

int n, m;
int a[15];
bool ans[maxN];

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	while (cin >> n)
	{
		cin >> m;
		fill (ans, ans+n+1, false);
		for (int i = 0; i < m; i++) 
		{
			cin >> a[i];
			ans[a[i]] = true;
		}
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j < m; j++)
				if (i > a[j]) ans[i] = (ans[i] || (!ans[i-a[j]]));
		}
		if (ans[n]) cout << "Stan wins" << endl; else cout << "Ollie wins" << endl; 
	}
}
