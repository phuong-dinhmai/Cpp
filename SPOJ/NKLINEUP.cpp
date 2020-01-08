#include <bits/stdc++.h>
#define ii pair <int, int>
#define mn first
#define mx second
using namespace std;

const int N = 1e5+7;

ii M[N][17];
int a[N], n, q;

int log2(int n) {
	return 31 - __builtin_clz(n);
}

void init()
{
	for (int j = 1; (1 << j) < n; j++)
	{
		for (int i = 0; i + (1 << j) - 1 < n; i++)
		{
			M[i][j].mn = min(M[i + (1 << (j-1))][j-1].mn, M[i][j-1].mn);
			M[i][j].mx = max(M[i + (1 << (j-1))][j-1].mx, M[i][j-1].mx);
		}
	}
}

void query(int x, int y)
{
	int lg = (int) log2(y-x+1);
	cout <<  max(M[x][lg].mx, M[y - (1 << lg) + 1][lg].mx) - min(M[x][lg].mn, M[y - (1 << lg) + 1][lg].mn) << endl;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i], M[i][0] = ii(a[i], a[i]);
	init();
	for (int i = 0; i < q; i++)
	{
		int x, y;
		cin >> x >> y;
		x--; y--;
		query(x, y);
	}
}
