#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

const int maxN = 255;
int test, t = 0;
int a[maxN*maxN];

int LIS(int n)
{
	int num = 0;
	vi lis(n);
	for (int i = 0; i < n; i++)
	{
		int pos = lower_bound(lis.begin(), lis.begin()+num, a[i]) - lis.begin();
		lis[pos] = a[i];
		if (pos == num) num++; 
	}
	return num;
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	//freopen("out.out","w",stdout);
	cin >> test;
	while(test--)
	{
		int n, q, p, m = 0, x;
		cin >> n >> p >> q;
		map <int, int> mp;
		for (int i = 0; i <= p; i++)
		{
			cin >> x;
			mp[x] = i+1;
		}
		for (int i = 0; i <= q; i++)
		{
			cin >> x;
			if (mp.count(x)) a[m++] = mp[x];
		}
		printf("Case %d: %d\n", ++t, LIS(m));
	}
}
