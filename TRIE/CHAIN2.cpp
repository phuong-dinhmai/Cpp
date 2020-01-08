#include <bits/stdc++.h>
using namespace std;

const int N = 26;

int n;
string str;
int ans = 0;

struct TRIE {
	TRIE *child[N];
	bool leaf;
	int len;
	TRIE() {
		for (int i = 0; i < 26; i++) child[i] = NULL;
		leaf = false;
		len = 0;
	}
	
	~TRIE() {
		for (int i = 0; i < 26; i++) delete child[i];
		leaf = false;
		len = 0;
	}
} * root = new TRIE();

void add(string s) {
	TRIE *cur = root;
	for (int i = 0; i < s.size(); i++) {
		int j = s[i] - 'a';
		if (cur -> child[j] == NULL) cur -> child[j] = new TRIE(), (cur -> child[j]) -> len = cur -> len;
		cur = cur -> child[j];
	}
	cur -> leaf = true;
	cur -> len ++;
	ans = max(ans, cur -> len);
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n;
	while (n--) {
		cin >> str;
		add(str);
	}
	cout << ans << endl;
}
