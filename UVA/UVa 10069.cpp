#include <bits/stdc++.h>
#define maxN 10005
#define maxM 105
using namespace std;

string s, ss, x;
string dp[maxN][maxM];
int test;

string add(string a, string b)
{
	while(a.size() < b.size()) a = "0" + a;
	while(b.size() < a.size()) b = "0" + b;
	int n = a.size() - 1;
	int tmp = 0;
	string res = "";
	for (int i = n; i >= 0; i--)
	{
		int t = a[i] - '0' + b[i] - '0' + tmp;
		res.push_back(t % 10 + '0');
		tmp = (a[i] - '0' + b[i] - '0' + tmp) / 10;
	}
	if (tmp != 0) res.push_back(tmp + '0');
	reverse(res.begin(), res.end());
	return res;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	cin >> test;
	while(test--)
	{
		s = ss = "0";
		cin >> x;
		s += x;
		cin >> x;
		ss += x;
		for (int j = 0; j <= ss.size(); j++) dp[0][j] = "0";
		for (int i = 0; i <= s.size(); i++) dp[i][0] = "1";
		for (int i = 1; i <= s.size(); i++)
		{
			for (int j = 1; j <= ss.size(); j++)
			{
				if (s[i] == ss[j]) dp[i][j] = add(dp[i-1][j-1], dp[i-1][j]); 
				else dp[i][j] = dp[i-1][j];
			}
		}
		cout << dp[s.size()-1][ss.size()-1] << endl;
	}
}
