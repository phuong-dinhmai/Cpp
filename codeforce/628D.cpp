#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2001;
const int mod = 1e9+7;

string a, b;
int m, d;
ll f[N][2][2][N];

ll F(int pos, bool x, bool y, int md)
{
	if (pos == a.size())
	{
		if (md == 0) return 1LL; else return 0LL;
	}
	if (f[pos][x][y][md] != -1) return f[pos][x][y][md];
	int lo, hi;
	if (x) lo = 0; else lo = a[pos] - '0';
	if (y) hi = 9; else hi = b[pos] - '0';
	ll ans = 0LL;
	for (int i = lo; i <= hi; i++)
	{
		if ((pos & 1) && (i != d)) continue;
		if ((!(pos & 1)) && (i == d)) continue;
		bool nx = (x || (i != lo));
		bool ny = (y || (i != hi));
		ans = (ans + F(pos+1, nx, ny, (md*10 + i) % m)) % mod;
	}
	//cout << ans << endl;
	return f[pos][x][y][md] = ans % mod;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> m >> d >> a >> b;
	memset(f, -1, sizeof(f));
	cout << F(0, 0, 0, 0) << endl;
}
