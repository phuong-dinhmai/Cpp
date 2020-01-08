#include <bits/stdc++.h>
using namespace std;

main(){
	map <string, int> mp;
	queue <string> st;
	string s;
	for (char i = 'a'; i <= 'z'; i++) { string ss=""; ss=ss+i; st.push(ss);}
	
	int cnt = 0;
	while(!st.empty())
	{
		string c = st.front();
		mp[c] = cnt;
		cnt++;
		if (c == "vwxyz") break;
		st.pop();
		for (char i = c[c.size() - 1] + 1; i <= 'z'; i++) st.push(c + i);
	}
	while (cin >> s)
	{
		if (mp.find(s) == mp.end()) cout << "0" << endl;
		else cout << mp.find(s)->second + 1<< endl;
	}
}
