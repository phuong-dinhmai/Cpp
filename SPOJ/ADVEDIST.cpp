#include <bits/stdc++.h>
#define inf (int) 1e9+7
#define maxN 1000
using namespace std;

int f[1000][1000];
string s, ss;

void init()
{
	for (int i = 0; i < maxN; i++)
		for (int j = 0; j < maxN; j++) f[i][j] = inf;
	for (int i = 0; i <= s.size() + 1; i++) f[i][0] = i;
	for (int j = 0; j <= ss.size() + 1; j++) f[0][j] = j;
}

main()
{
	//freopen ("in.inp","r",stdin);
	//freopen ("out.out","w",stdout); 
	
	while (cin >> s >> ss)
	{
		if (s == "*" && ss == "*") break; 
		s.insert(0,"0");
		ss.insert(0,"0");
		init();
		for (int i = 1; i < s.size(); i++)
			for (int j = 1; j < ss.size(); j++)
			{
				if (s[i] == ss[j]) f[i][j] = min (f[i][j], f[i-1][j-1]); else f[i][j] = min(f[i-1][j-1]+1, f[i][j]);
				f[i][j] = min (f[i][j], f[i-1][j] + 1);
				f[i][j] = min (f[i][j], f[i][j-1] + 1);
				for (int k = i-1; k > 0; k--) 
					if (s[i] == ss[j-1] && ss[j] == s[k] && j >= 2) f[i][j] = min (f[i][j], f[k-1][j-2] + (i - k));
			}
		/*for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < ss.size(); j++) cout << f[i][j] << " ";
			cout << endl;
		}*/
		cout << f[s.size() - 1][ss.size() - 1] << endl;
	}
}
