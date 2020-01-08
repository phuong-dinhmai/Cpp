#include <bits/stdc++.h>
#define ll long long
#define lli pair <ll, int>
#define ill pair <int, ll>
#define vii vector <ill>
#define vvii vector <vii>
#define fi first
#define se second
using namespace std;

const int N = 1e5+7;
const ll inf = 1e18+7;
const ll mod = 123456789;

vvii edge1, edge2;
int x[N], y[N];
int n, m, start, en;
ll d1[N], d2[N], cnt1[N], cnt2[N], cost[N];
bool vis[N];

void dijikstra1()
{
	priority_queue <lli, vector <lli>, greater <lli> > pq;
	memset(vis, 0, sizeof(vis));
	fill(d1, d1 + N, inf);
	pq.push(lli(0LL, start));
	cnt1[start] = 1LL;
	d1[start] = 0LL; 
	while (!pq.empty())
	{
		int u = (pq.top()).se;
		ll dis = (pq.top()).fi;
		pq.pop();
		vis[u] = true;
		if (d1[u] < dis) continue;
		for (int i = 0; i < edge1[u].size(); i++)
		{
			ill v = edge1[u][i];
			if (d1[v.fi] > d1[u] + v.se && !vis[v.fi])
			{
				d1[v.fi] = d1[u] + v.se;
				pq.push(lli(d1[v.fi], v.fi));
				cnt1[v.fi] = cnt1[u];
			}
			else
			{
				if (d1[v.fi] == d1[u] + v.se) cnt1[v.fi] += cnt1[u], cnt1[v.fi] %= mod;
			}
		}
	}
}

void dijikstra2()
{
	priority_queue <lli, vector <lli>, greater <lli> > pq;
	fill(d2, d2+N, inf);
	memset(vis, 0, sizeof(vis));
	pq.push(lli(0LL, en));
	cnt2[en] = 1LL;
	d2[en] = 0LL;
	while (!pq.empty())
	{
		int u = (pq.top()).se;
		ll dis = (pq.top()).fi;
		pq.pop();
		if (d2[u] < dis) continue;
		for (int i = 0; i < edge2[u].size(); i++)
		{
			ill v = edge2[u][i];
			if (d2[v.fi] > d2[u] + v.se && !vis[v.fi])
			{
				d2[v.fi] = d2[u] + v.se;
				pq.push(lli(d2[v.fi], v.fi));
				cnt2[v.fi] = cnt2[u];
			}
			else
			{
				if (d2[v.fi] == d2[u] + v.se) cnt2[v.fi] += cnt2[u], cnt2[v.fi] %= mod;
			}
		}
	}
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> m >> start >> en;
	edge1.assign(n+1, vii());
	edge2.assign(n+1, vii());
	for (int i = 0; i < m; i++)
	{
		cin >> x[i] >> y[i] >> cost[i];
		edge1[x[i]].push_back(ill(y[i], cost[i]));
		edge2[y[i]].push_back(ill(x[i], cost[i]));
	}
	
	dijikstra1();
	dijikstra2();
	
	//for (int i = 1; i <= n; i++) cout << d1[i] << " "; cout << endl;
	//for (int i = 1; i <= n; i++) cout << d2[i] << " "; cout << endl; 
	
	for (int i = 0; i < m; i++)
	{
		if (d1[x[i]] + cost[i] + d2[y[i]] == d1[en] && cnt1[x[i]] * cnt2[y[i]] % mod == cnt1[en]) cout << "YES\n";
		else if (d1[x[i]] + cost[i] + d2[y[i]] == d1[en] && cost[i] != 1) cout << "CAN 1\n";
		else if (d1[x[i]] + d2[y[i]] < d1[en] - 1)
		{
			int k = cost[i] - (d1[en] - d1[x[i]] - d2[y[i]]) + 1;
			if (k >= 1) cout << "CAN " << k << "\n";
			else cout << "NO\n"; 
		} 
		else cout << "NO\n";
	}
}
