#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

int n;

vi find(vi a)
{
	vi lis(a.size()), res(a.size());
	int lis_count = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int pos = lower_bound(lis.begin(), lis.begin()+lis_count, a[i]) - lis.begin();
		lis[pos] = a[i];
		if (pos == lis_count) lis_count++;
		res[i] = pos+1;
	}
	return res;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	ios_base :: sync_with_stdio(false);
	while(cin >> n)
	{
		vi a(n);
		vi LIS, LDS;
		int ans = 0;
		for (int i = 0; i < n; i++) cin >> a[i];
		LIS = find(a);
		reverse(a.begin(), a.end());
		LDS = find(a);
		reverse(LDS.begin(), LDS.end());
		for (int i = 0; i < n; i++)
		{
			ans = max(ans, 2*min(LIS[i], LDS[i]) - 1);
		}
		printf("%d\n", ans);
	}
}
