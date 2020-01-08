#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+7;

struct data{
	int l, r, pos;
} q[maxN];

int n, m, a[maxN];
int answer = 0;
int cnt[maxN];
int ans[maxN];
int x, L, R;

bool cmp(const data &a, const data &b)
{
	return (((a.l / x) == (b.l /x) && (a.r < b.r)) || ((a.l / x)  < (b.l / x)));
}

void add(int pos)
{
	if (pos == 0 || a[pos] > n) return;
	answer -= (cnt[a[pos]] == a[pos]);
	cnt[a[pos]]++;
	answer += (cnt[a[pos]] == a[pos]);
}

void remove(int pos)
{
	if (pos == 0 || a[pos] > n) return;
	answer -= (cnt[a[pos]] == a[pos]);
	cnt[a[pos]]--;
	answer += (cnt[a[pos]] == a[pos]);
}

main(){
	//freopen("in.inp","r",stdin);
	//ios_base :: sync_with_stdio(false); cin.tie(0);
	L = R = 0;
	scanf("%d %d", &n, &m);
	x = sqrt(n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) 
	{
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].pos = i;
	}
	sort(q, q+m, cmp);
	for (int i = 0; i < m; i++) 
	{ 
		while(R < q[i].r) add(++R);
		while(R > q[i].r) remove(R--);
		while(L < q[i].l) remove(L++);
		while(L > q[i].l) add(--L);
		ans[q[i].pos] = answer;
	}
	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
}
