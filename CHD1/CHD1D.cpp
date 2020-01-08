#include <bits/stdc++.h>
using namespace std;

main(){
	freopen("in.inp","r",stdin);
	int test;
	cin >> test;
	while (test--){
		int n, player1, player2;
		queue <int> card_1, card_2;
		cin >> n;
		cin >> player1;
		for (int i = 0; i < player1; i++){
			int a;
			cin >> a;
			card_1.push(a);
		}
		cin >> player2;
		for (int i = 0; i < player2; i++) {
			int b;
			cin >> b;
			card_2.push(b);
		}
		map <queue <int>, int> mp1, mp2;
		mp1[card_1]++;
		mp2[card_2]++;
		int res = 0;
		while (1) {
			++res;
			int x = card_1.front();
			card_1.pop();
			int y = card_2.front();
			card_2.pop();
			if (x > y) {
				card_1.push(y), card_1.push(x);
			} else {
				card_2.push(x); card_2.push(y);
			}
				if (card_1.empty()) { 
				cout << res << " 2" << endl;
				break;
			}
			if (card_2.empty()) {
				cout << res << " 1" << endl;
				break;
			}
			if (mp1[card_1] & mp2[card_2]) {
				cout << -1 << endl;
				break;
			}
			mp1[card_1]++;
			mp2[card_2]++;
		}
		
	}
}
