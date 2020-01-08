#include <bits/stdc++.h>
#define inf (int) (1e9+7)
using namespace std;

int dp[15][15];
int pre[15][15];
int a[30];
int n, test;

int cutting(int start, int end)
{
	if (dp[start][end] != -1) return dp[start][end];
	int mn = dp[start][end];
	if (start == end) return 0;
	for (int i = start; i < end; i++)
	{
		int res = cutting(start, i) + cutting(i + 1, end) + a[start - 1] * a[i] * a[end];
		if (mn == -1 || res < mn)
		{
			mn = res;
			pre[start][end] = i;
		}
	}
	return (dp[start][end] = mn);
}

void result(int start, int end)
{
	if (start == end) printf("A%d", start);
	else{
		printf("(");
		result(start, pre[start][end]);
		printf(" x ");
		result(pre[start][end] + 1, end);
		printf(")");
	}
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	while (scanf("%d", &n) && n)
	{
		test++;
		for (int i = 0; i < 15; i++)
			for (int j = 0; j < 15; j++) {dp[i][j] = -1; pre[i][j] = -1;}
		for (int i = 0; i < n; i++) scanf("%d %d", &a[i], &a[i+1]);
		cutting(1, n);
		printf("Case %d: ", test);
		//printf("%d\n", dp[1][n]);
		result(1,n);
		printf("\n");
	}
}
