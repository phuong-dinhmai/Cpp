#include <bits/stdc++.h>
#define vi vector <int>
#define ii pair <int, int>
#define iii pair <int, ii>
#define viii vector <iii>
#define fi first
#define se second
using namespace std;

vi father, size_of;
viii ways;
int n, m;
int ans = 0;

void init()
{
	father.assign(n+1, 0);
	for (int i = 0; i <= n; i++) father[i] = i;
	size_of.assign(n+1, 1);
}

int find(int x)
{
	return (x == father[x]? x: find(father[x]));
}

bool same_set(int x, int y)
{
	return (find(x) == find(y));
}

void make_set(int i, int j)
{
	int x = find(i);
	int y = find(j);
	if (size_of[x] < size_of[y]) swap(x,y);
	father[y] = x;
	size_of[x] += size_of[y];
	return;
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false);
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		ways.push_back(make_pair(cost, ii(x,y)));
	}
	sort(ways.begin(), ways.end());
	for (int i = 0; i < m; i++)
	{
		int v = ways[i].se.fi;
		int u = ways[i].se.se;
		if (!same_set(u, v)) 
		{
			make_set(u,v);
			ans += ways[i].fi;
		}
	}
	cout << ans << endl;
}
