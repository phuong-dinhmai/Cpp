#include <bits/stdc++.h>
#define maxN 10001
using namespace std;

int mod;
string str;
int f[maxN][maxN];

main(){
	//freopen("in.inp","r",stdin);
	cin >> str;
	cin >> mod;
	int n = str.size();
	for (int i = 0; i <= n; i++) f[i][0] = f[0][i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			f[i][j] = (f[i-1][j] + f[i][j-1]) % mod;
			if (str[i-1] != str[j-1]) f[i][j] = (f[i][j] - f[i-1][j-1] + mod) % mod;
		}
	cout << f[n][n];
}
