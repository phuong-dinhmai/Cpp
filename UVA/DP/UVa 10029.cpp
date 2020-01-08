#include <bits/stdc++.h>
using namespace std;

map <string, int> mp;
string str;
int ans = 0;

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	ios_base :: sync_with_stdio(false);
	cin.tie(0);
	while(cin >> str)
	{
		int len = 1;
		
		string s;
		// erase a char
		for (int i = 0; i < str.size(); i++)
		{
			s = str;
			s.erase(i, 1);
			if (mp.count(s)) len = max(len, mp[s] + 1);
		}
		
		// insert a char
		for (int i = 0; i <= str.size(); i++)
		{
			for (char c = 'a'; c <= 'z'; c++)
			{
				s = str;
				s.insert(i, 1, c);
				if (mp.count(s)) len = max(len, mp[s] + 1);
			}
		} 
		
		// change a char into another char
		for (int i = 0; i < str.size(); i++)
		{
			for (char c = 'a'; c <= 'z'; c++)
			{
				s = str;
				s[i] = c;
				if (mp.count(s)) len = max(len, mp[s] + 1);
			}
		}
		mp[str] = len;
		ans = max(ans, len);
	}
	//for (map <string, int> :: iterator it = mp.begin(); it != mp.end(); it++) cout << it -> first << " " << it -> second << endl;
	printf("%d\n", ans);
}
