#include <bits/stdc++.h>
using namespace std;

const int N = 3005;

char face[6][10] = {"front", "back", "left", "right", "top", "bottom"};
int a[6];
int trace[N], f[N], num[N], df[N], bot[N], top[N];
int t = 0;
int n, m, k, ans;

void _trace(int i)
{
	if (trace[i] == -1) 
	{
		printf("%d %s\n", num[i], face[df[i]]);
		return;
	}
	_trace(trace[i]);
	printf("%d %s\n", num[i], face[df[i]]);
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	while(cin >> n && n)
	{
		m = 0, ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 6; j++) cin >> a[j];
			for (int j = 0; j < 6; j++)
			{
				num[m] = i+1;
				df[m] = j;
				bot[m] = a[j];
				if (j & 1) top[m] = a[j-1]; else top[m] = a[j+1];
				m++;
			}
		}
			
		memset(f, 0, sizeof(f));
		memset(trace, -1, sizeof(trace));
		
		for (int i = 0; i < m; i++)
			for (int j = i+1; j < m; j++)
			{
				if (num[i] < num[j] && top[i] == bot[j] && f[j] < f[i] + 1) 
				{
					f[j] = f[i] + 1;
					trace[j] = i;
				} 	
			}
		
		for (int i = 0; i < m; i++) 
			if (ans < f[i]) ans = f[i], k = i;
		if (t) printf("\n");
		printf("Case #%d\n%d\n", ++t, ans+1);
		_trace(k);
	}
}
