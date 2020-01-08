#include <bits/stdc++.h>
#define maxN 1005
using namespace std;

int n, m;
int test;
bool un_safe[maxN][maxN];
int dp[maxN][maxN];
string str;

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	ios_base :: sync_with_stdio(false);
	cin >> test;
	while(test--)
	{
		getchar();
		cin >> n >> m;
		cin.ignore();
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++) 
			{
				un_safe[i][j] = false;
				dp[i][j] = 0;
			}
		for (int i = 1; i <= n; i++)
		{
			getline(cin, str);
			stringstream s(str);
			int j;
			s >> j;
			while(s >> j)
			{
				un_safe[i][j] = true;
			}
		}
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (un_safe[i][j]) continue;
				if (i > 1) dp[i][j] += dp[i-1][j];
				if (j > 1) dp[i][j] += dp[i][j-1];
			}
		}
		/*for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= m; j++) cout << un_safe[i][j] << " ";
			cout << endl;
		}*/
		printf("%d\n", dp[n][m]);
		if (test) printf("\n"); 
	}
}
