#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 1e5+7;
const int max_val = 2e6+7;

struct data {
	int l, r, pos;
} q[maxN];

ll cnt[max_val];
int a[maxN];
ll ans[maxN];
int n, m, k, x, L, R;
ll answer = 0;

bool cmp(const data &a, const data &b)
{
	return ((a.l / x) < (b.l / x) || (a.l / x == b.l / x && a.r < b.r));
}

void add(int i)
{
	if (i < 0) return;
	answer += cnt[a[i] ^ k];
	cnt[a[i]]++;
}

void remove(int i)
{
	if (i < 0) return;
	cnt[a[i]]--;
	answer -= cnt[a[i] ^ k];
}

void query(int i)
{
	while(R < q[i].r) add(++R);
	while(R > q[i].r) remove(R--);
	while(L < q[i].l) remove(L++);
	while(L > q[i].l) add(--L);
}

main(){
	//freopen("in.inp","r",stdin);
	scanf("%d %d %d", &n, &m, &k);
	a[0] = 0;
	L = R = 0;
	x = sqrt(n);
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] = a[i-1] ^ a[i];
	for (int i = 0; i <= m; i++) 
	{
		scanf("%d %d", &q[i].l, &q[i].r);
		q[i].l--;
 		q[i].pos = i;
	}
	add(0);
	sort(q, q+m, cmp);
	for (int i = 0; i < m; i++) query(i), ans[q[i].pos] = answer;
	for (int i = 0; i < m; i++) printf("%I64d\n", ans[i]);
}
