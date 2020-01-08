#include <bits/stdc++.h>
#define inf (int) (1e9+7)
using namespace std;

int a[1000];
int f[1002][1002];
int n, l;

int cutting(int start, int end)
{
	if (start + 1 == end) return 0;
	if (f[start][end] != -1) return f[start][end];
	int mn = inf;
	for (int i = start + 1; i < end; i++)
		{
			int cost = cutting(start, i) + cutting(i, end) + a[end] - a[start];
			mn = min(cost, mn);
		}
	return f[start][end] = mn;
}

void init()
{
	for (int i = 0; i < 1002; i++)
		for (int j = 0; j < 1002; j++) f[i][j] = -1;
}


main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	while (cin >> l && l != 0)
	{
		cin >> n;
		init();
		for (int i = 1; i <= n; i++) cin >> a[i];
		a[n+1] = l;
		a[0] = 0;
		cout << "The minimum cutting is " << cutting(0, n+1)  << "."<< endl;
	}
}
