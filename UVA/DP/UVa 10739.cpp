#include <bits/stdc++.h>
using namespace std;

const int maxN = 1005;

int test, f[maxN][maxN];
string str;
int d = 0;

int F(int start, int en)
{
	if (start >= en) return 0;
	if (f[start][en] != -1) return f[start][en];
	if (str[start] == str[en]) return f[start][en] = F(start+1, en-1);
	else
	{
		int ans = min(min(F(start+1, en), F(start, en-1)), F(start+1, en-1));
		return f[start][en] = ans+1;
	}
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	cin >> test;
	while(test--)
	{
		d++;
		memset(f, -1, sizeof(f));
		cin >> str;
		printf("Case %d: %d\n",d, F(0, str.size() - 1));
	}
}
