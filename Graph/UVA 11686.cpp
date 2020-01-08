#include <bits/stdc++.h>
#define WHITE 1
#define GRAY 0
#define BLACK 2
#define vi vector <ll>
#define maxN 1000001
#define ll long long 
using namespace std;

vi check[maxN];
ll ok [maxN];
ll ans[maxN];
ll n, r;
bool res;
void init()
{
	for (ll i = 0; i < maxN; i++)
	{
		ok[i] = WHITE;
		check[i].clear();
		ans[i] = 0;
	}
	res = false;
	r  = 0;
}

void topo(ll k)
{
	ok[k] = GRAY;
	for (ll i = 0; i <check[k].size(); i++)
		if (ok [check[k][i]] == WHITE) topo(check[k][i]); else 
			if (ok[check[k][i]] == GRAY) res = true;
	ok[k] = BLACK;
	ans[r++] = k;
}

main(){
	long long m;
	freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	while (cin >> n >> m)
	{
		if (n == 0  && m == 0) break;
		
		init();
		
		for (long long i = 0; i < m; i++) 
		{
			ll x,y;
			cin >> x >> y;
			check[x].push_back(y);
		}
					
		for (ll i = 1; i <= n; i++)
		if (ok[i] == WHITE)
		{
			topo(i);
		}
	
		if (res) cout << "IMPOSSIBLE" << endl;
		else
		{
			for (ll i = r - 1  ; i >= 0; i--)  cout << ans[i] << endl;
		}
		
	}
}

