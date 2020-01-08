#include <bits/stdc++.h>
#define ii pair <int, int>
#define fi first
#define se second
using namespace std;

const int N = 1e4+7;

int n, m, b;
ii a[N];

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> b >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].fi >> a[i].se;
	}
	a[m].fi = b;
	a[m].se = n;
	m++;
	sort(a, a+m);
	
	for (int mask = 1; mask < (1 << 5); mask++)
	{
		int at_least = 0, at_most = 0;
		
		int pre_dis = 0, pre_num = 0;
		for (int i = 0; i < m; i++)
		{
			int dis = a[i].fi, num = a[i].se;
			int matching = 0, remain = 0;
			
			for (int j = pre_dis+1; j <= dis; j++)
			{
				if (mask & (1 << (j % 5))) matching++; else remain++;
			}
			
			if (num < pre_num) 
			{
				cout << "unfair\n";
				return 0;
			}
			
			if (dis - pre_dis < num - pre_num)
			{
				cout << "unfair\n";
				return 0;
			}
			
			at_least += max(0, num - pre_num - remain);
			at_most += min(num - pre_num, matching);
			
			pre_dis = dis;
			pre_num = num;
		}
		
		int val = __builtin_popcount(mask)*n/5;
		if (!(at_least <= val && val <= at_most)) 
		{
			cout << "unfair\n";
			return 0;
		}
	}
	
	cout << "fair\n";
}
