#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 500005;
const ll inf = 1e18+7;

int n;
ll x[maxN], y[maxN];
ll pre[2][2];
ll pre_y;
int res = 0;

void init(int i)
{
	pre_y = x[i] + y[i];
	pre[!(i & 1)][0] = pre[!(i & 1)][1] = inf;
	pre[i & 1][0] = 0;
	pre[i & 1][1] = pre_y;
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	init(1);
	for (int i = 2; i <= n; i++)
	{
		int kind = i % 2;
		if (x[i] + y[i] >= pre_y)
		{
			pre[kind][0] = min(pre[kind][0], pre_y);
			pre_y = (x[i] + y[i] - pre_y);
			pre[kind][1] = min(pre[kind][1], pre_y);
			res++;
		} 
		else
		{
			ll d = pre_y - (x[i] + y[i]);
			if (pre[kind][0] >= d && pre[!kind][1] >= d)
			{
				pre[kind][0] = min(pre[kind][0]-d, x[i] + y[i]), pre[kind][1] = 0;
				pre[!kind][0] += d, pre[!kind][1] -= d;
				pre_y = 0;
				res++;
			} 
			else
			{
				init(i);
			}
		}
		//cout << i << " " << pre_y << " " << pre[kind][0] << " " << pre[kind][1] << " " << pre[!kind][0] << " " << pre[!kind][1] << endl;
		//cout << res << endl;
	}
	printf("%d\n", res);
}
