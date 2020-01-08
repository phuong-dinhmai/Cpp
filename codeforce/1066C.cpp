#include <bits/stdc++.h>
using namespace std;

int n;
map <int, pair <int, int> > mp;
char side[200006];

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	int left = 0, right = 0;
	int num = 0;
	while(n--){
		char c;
		int id;
		cin >> c >> id;
		if (c == 'L') left++;
		if (c == 'R') right++;
		if (c != '?') 
		{
			side[id] = c;
			num++;
			mp[id] = make_pair(left, right);
		}
		if(c == '?'){
			int ans;
			//cout << side[id] << " " << right - mp[id].second << " " << num - 1 - right + mp[id].second << endl;
			if (side[id] == 'R') ans = min(right - mp[id].second, num - 1 - right + mp[id].second);
			else ans = min(left - mp[id].first, num - 1 - left + mp[id].first);
			cout << ans << endl;
		}
	}
}
