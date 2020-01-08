#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 2e5+7;
const int max_val = 1e6+7;

struct ask{
	int l, r, pos;
} q[maxN];

int n, m;
ll cnt[max_val];
ll answer = 0;
ll ans[maxN], a[maxN], x;
int L, R;

bool cmp(const ask &a, const ask &b)
{
	return (((a.l / x) < (b.l / x)) || ((a.l / x) == (b.l / x) && a.r < b.r));
}

void add(int i, int type)
{
	answer += a[i]*(1 + type*2*cnt[a[i]]);
	cnt[a[i]] += type;
}

void query(int i)
{
	while(R < q[i].r) add(++R, 1);
	while(R > q[i].r) add(R--, -1);
	while(L < q[i].l) add(L++, -1);
	while(L > q[i].l) add(--L, 1);
}

main(){
	//freopen("in.inp","r",stdin);
	//ios_base :: sync_with_stdio(false); cin.tie(0);
	scanf("%d %d", &n, &m);
	x = 450;
	L = R = 0;
	memset(cnt, sizeof(cnt), 0);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].pos = i;
	}
	sort(q, q+m, cmp);
	//for (int i = 0; i < m; i++) cout << q[i].l << " " << q[i].r << endl;
	for (int i = 0; i < m; i++)
	{
		query(i);
		ans[q[i].pos] = answer;
	}
	for (int i = 0; i < m; i++) printf("%I64d\n", ans[i]);
}
