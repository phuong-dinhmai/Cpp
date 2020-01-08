#include <bits/stdc++.h>
#define inf (long) (1e9+7)
#define vi vector <long>
using namespace std;

main(){
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout);
	
	long k;
	vi a;
	while (scanf("%ld", &k) == 1) a.push_back(k);
	vi lis(a.size(), inf);
	vi trace(a.size());
	vi lis_pos(a.size());
	long res = 0;
	long lis_end = 0;
	for (int i = 0; i < a.size(); i++)
	{
		long pos = lower_bound(lis.begin(), lis.begin() + res, a[i]) - lis.begin();
		lis[pos] = a[i];
		lis_pos[pos] = i;
		trace[i] = pos ? lis_pos[pos - 1] : -1; 
		if (pos + 1 > res)
		{
			res = pos + 1;
			lis_end = i;
		}
	} 
	printf("%d\n-\n", res);
	vi ans;
	while (lis_end != -1) 
	{
		ans.push_back(a[lis_end]);
		lis_end = trace[lis_end];
	}
	for (int i = res - 1; i >= 0; i--) printf("%ld\n", ans[i]);
}
