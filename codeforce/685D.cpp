#include <bits/stdc++.h>
#define vi vector <int>
#define ll long long
using namespace std;

const int N = 3e5+7;

struct data
{
	int lft, rght, y, add;
	data (int _lft, int _rght, int _y, int _add)
	{
		lft = _lft, rght = _rght, y = _y, add = _add;
	}
	
	bool operator < (const data &other)
	{
		return (y < other.y || (y == other.y && add < other.add));
	}
};

vector <data> Q;
vi lis;
int n, k;
ll ans[N], cnt[N], last[N];

main()
{
	//freopen("in.inp","r",stdin);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		lis.push_back(x-k), lis.push_back(x);
		Q.push_back(data(x-k, x, y-k, 1));
		Q.push_back(data(x-k, x, y, -1));
	}
	
	sort(lis.begin(), lis.end());
	lis.resize(unique(lis.begin(), lis.end()) - lis.begin());
	sort(Q.begin(), Q.end());
	
	for (int i = 0; i < 2*n; i++)
	{
		data t = Q[i];
		int pos = lower_bound(lis.begin(), lis.end(), t.lft) - lis.begin();
		while (pos < lis.size() && lis[pos] < t.rght)
		{
			ans[cnt[pos]] += 1LL*(lis[pos+1] - lis[pos])*(t.y - last[pos]);
			cnt[pos] += t.add;
			last[pos] = t.y;
			pos++;
		}
	}
	
	for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]); printf("\n");
}
