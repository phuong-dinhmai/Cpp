#include <bits/stdc++.h>
#define vi vector <int>
#define maxN (500050)
using namespace std;

int n, m;
int s[maxN][33];
int a[maxN];
vi num[maxN];

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= 32; j++) s[i][j] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		num[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 32; j++) 
		{
			int t = j-1;
			s[i][j] = s[i-1][j] + ((a[i] >> t) & 1);
		}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		int ans = 0;
		for (int j = 1; j <= 32; j++)
		{
			int k = s[y][j] - s[x-1][j];
			//cout << ans << " " << num << endl;
			if (k*2 > (y-x+1)) ans += (1 << (j-1));
		}
		//cout << ans << endl;
		//cout << endl; 
		int bgi = lower_bound(num[ans].begin(), num[ans].end(), x) - num[ans].begin();
		int en = upper_bound(num[ans].begin(), num[ans].end(), y) - num[ans].begin();
		en--;
		//cout << ans << " " << bgi << " " << en << endl;
		if (2*(en - bgi+1) > (y-x+1)) printf("%d\n", ans); else printf("0\n");
	}
}
