#include <bits/stdc++.h>
#define vi vector<int>
#define vii vector <vi>
#define maxN 2001
using namespace std;

string s, ss;
vi f[maxN];

main(){
	cin >> s;
	ss = s;
	string ans = "";
	for (int i = 0; i <= s.size(); i++) f[i].assign(s.size() + 1, 0);
	reverse(s.begin(), s.end());
	for (int i = 1; i <= s.size(); i++)
		for (int j = 1; j <= ss.size(); j++)
		{
			if (s[i-1] == ss[j-1]) f[i][j] = f[i-1][j-1] + 1;
			else f[i][j] = max(f[i-1][j], f[i][j-1]);
			
		}
	int i = s.size();
	int j = s.size();
	//cout << f[i][j] << endl;
	while (i && j)
	{
		if (s[i-1] == ss[j-1])
		{
			ans = s[i-1] + ans;
			i--;
			j--;
		}
		else if (f[i][j] == f[i-1][j]) i--;
		else j--;
	}
	cout << ans << endl;
}
