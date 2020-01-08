#include <bits/stdc++.h>
#define ll long long
#define vi vector <long long>
using namespace std;

const int N = 1e6+7;

struct fenwick_tree
{
	vi t;
	void init(int num) {t.assign(num, 0);}
	void update(int pos, int val)
	{
		for (; pos < t.size(); pos += pos & (-pos)) t[pos] += val;
	}
	
	ll get(int pos)
	{
		ll res = 0LL;
		for (; pos > 0; pos -= pos & (-pos)) res += t[pos];
		return res;
	}
} BIT1, BIT2;

int n, k, num;
int a[N];
ll sum = 0LL, ans, val = 0, pos = N, x;
int mx = 0;

ll query()
{
	int lo = 0;
	int hi = mx;
	while (lo < hi)
	{
		int mid = (lo + hi) >> 1;
		int v = BIT1.get(mid);
		if (2*v < k) lo = mid+1; else hi = mid;
		if (lo + 1 == hi) break;
	}
	if (2*BIT1.get(lo) >= k) val = lo, num = BIT1.get(lo); else val = hi, num = BIT1.get(hi);
	//cout  << val << " " << val*num - BIT2.get(val) << " " << sum << " " << sum - BIT2.get(val) - val*(k-num) << endl;
	return (val*num - BIT2.get(val) + sum - BIT2.get(val) - val*(k-num));
}

main(){
//	freopen("in.inp","r",stdin);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i]++, mx = max(mx, a[i]);
	BIT1.init(mx+7), BIT2.init(mx+7);
	
	for (int i = 1; i <= k; i++) 
	{
		sum += a[i];
		BIT1.update(a[i], 1);
		BIT2.update(a[i], a[i]);
	}
	
	ans = query();
	pos = 1, x = val;
	for (int i = 2; i+k-1 <= n; i++)
	{
		sum -= a[i-1], sum += a[i+k-1];
		BIT1.update(a[i-1], -1);
		BIT1.update(a[i+k-1], 1);
		BIT2.update(a[i-1], -a[i-1]);
		BIT2.update(a[i+k-1], a[i+k-1]);
		ll res = query();
		if (ans > res)
		{
			ans = res;
			pos = i;
			x = val;
		}
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= n; i++)
	{
		if (pos <= i && i <= pos+k-1) printf("%d\n", x-1); else printf("%d\n", a[i]-1);
	}
}
