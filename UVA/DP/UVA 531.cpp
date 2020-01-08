#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

map <string, int> mp;
map <int, string> mp2;
string s;
vi a, b;
int k = 0;
int ok = 0;

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	while (cin >> s)
	{
		if (s == "#") ok++;
		if (ok == 0)
		{
			map <string, int> :: iterator it = mp.find(s);
			if (it != mp.end()) 
			{
				mp2[it -> second] = s;  
				a.push_back(it -> second);
			}
			else
			{
				mp2[k] = s;
				mp[s] = ++k;
				a.push_back(k);
			}
		}
		if (ok == 1)
		{
			map <string, int> :: iterator it = mp.find(s);
			if (it != mp.end()) 
			{
				mp2[it -> second] = s;  
				b.push_back(it -> second);
			}
			else
			{
				mp2[k] = s;
				mp[s] = ++k;
				b.push_back(k);
			}
		}
		if (ok == 2)
		{
			int f[101][101];
			int pre[101][101];
			for (int i = 0; i < a.size(); i++) f[i][0] = 0;
			for (int j = 0; j < b.size(); j++) f[0][j] = 0;
			for (int i = 1; i <= a.size(); i++)	
				for (int j = 1; j <= b.size(); j++) 
					if (a[i-1] == b[j-1]) 
					{
						f[i][j] = f[i-1][j-1] + 1;
						pre[i][j] = 0;
					}
					else 
					{
						if (f[i-1][j] > f[i][j-1]) 
						{
							f[i][j] = f[i-1][j];
							pre[i][j] = 1;
						}
						else
						{
							f[i][j] = f[i][j - 1];
							pre[i][j] = 2;
						}
					}
			int n = a.size(), m = b.size();
			vi ans;
			while (n && m)
			{
				if (pre[n][m] == 0) 
				{ 
					ans.push_back(a[n-1]);
					n--; m--;
				}
				else
				if (pre[n][m] == 1) 
				{
					n--;
				}
				else m--;
			}
			for (int i = ans.size() - 1; i >= 0; i--) 
			{
				cout << mp2[ans[i]];
				if (i != 0) cout << " ";
			}
			cout << endl;
			ok = 0;
			mp.clear();
			mp2.clear();
			a.clear();
			b.clear();
		}
	}
	
}
