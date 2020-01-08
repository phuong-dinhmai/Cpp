#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxN = 205;
const ll mod = 100000LL;

int n;
char s[maxN];
char op[4] = {'(', '{', '['};
char cl[4] = {')', '}', ']'};
bool flag = false;
ll f[maxN][maxN];

ll F(int start, int en)
{
	if (f[start][en] != -1) return f[start][en];
	if (start > en) return 1LL;
	for (int j = 0; j < 3; j++)
		if (s[start] == cl[j] || s[en] == op[j]) return 0LL;
	ll ans = 0;
	for (int i = start+1; i <= en; i += 2)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((s[start] == op[j] || s[start] == '?') && (s[i] == cl[j] || s[i] == '?')) 
			{
				ans += F(start+1, i-1)* F(i+1, en);
				if (ans >= mod)
				{
					ans %= mod;
					flag = true;
				}
			}
		}
	}
	//cout << start << " " << en << "  " << ans << endl;
	return f[start][en] = (ans + mod) % mod;
}

int main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	memset(f, -1, sizeof(f));
	for (int i = 0; i < n; i++) cin >> s[i];
	ll ans = F(0, n-1);
	if (flag) printf("%05lld\n", ans); else printf("%lld\n", ans);
	return 0;
}
