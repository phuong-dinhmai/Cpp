#include <bits/stdc++.h>
using namespace std;
 
#define type first
#define val second 
 
const int maxN = 3e4+5;
 
main() {
	//freopen("in.inp","r",stdin);
	for (char d; cin >> d;) {
		string s(1, d);
		for (char k;;){
			cin >> k;
			if (k == '#') break;
			s += k;
		}
		char ans[30000], st[s.size()];
		vector <pair <int, int> > str;
		memset(ans, 0, sizeof(ans));
		 		
 		int num = 0;
		for (int i = 0; i < s.size(); ){
			if (s[i] == '.') {
				str.push_back(make_pair(-1, 1));
				i++;
				continue;
			}
			if (s[i] == '[') {
				str.push_back(make_pair(str.size(), 0));
				st[++num] = str.size()-1;
				i++;
				continue;
			}
			if (s[i] == ']') {
				int x = st[num];
				num--;
				str.push_back(make_pair(str.size(), x));
				str[x].val = str.size()-1;
				i++;
				//cout << str.size() << " " << x << endl;
				continue;
			}
			int j = i+1;
			while (s[i] == s[j] && j < s.size()) j++;
			if (s[i] == '<') str.push_back(make_pair(-2, (i-j)));
			else if (s[i] == '>') str.push_back(make_pair(-2, j-i));
			else if (s[i] == '+') str.push_back(make_pair(-3, j-i));
			else if (s[i] == '-') str.push_back(make_pair(-3, i-j));
			i = j;
		}
 
		//for (int i = 0; i < str.size(); i++) cout << str[i].type << " " << str[i].val << endl;	
		/* -1 print 
		   -2 move
		   -3 add
		   type > val close
		   type < val open
		*/
 
		int cnt = 0;
		for (int i = 0; i < str.size(); i++) {
			// ngoac la loop
			if (str[i].type < 0){
				if (str[i].type == -1) {
					putchar(ans[cnt]);
				}
				//cout << i << " ";
				if (str[i].type == -2) cnt += str[i].val;
				if (str[i].type == -3) ans[cnt] += str[i].val;	
			} else {
				if (str[i].type > str[i].val) {
					if (ans[cnt]) {
						i = str[i].val-1;
					}
				} else {
					if (!ans[cnt]){
						i = str[i].val-1;
					} 
				}
			}
		}
	}
}
