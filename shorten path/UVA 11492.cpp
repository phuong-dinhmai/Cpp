#include <bits/stdc++.h>
#define vi vector <int>
#define ii pair <int, int>
#define vii vector <pair <ii, char> > 
#define maxN 5000
#define inf (int) (1e9+7)
using namespace std;

typedef struct state
{
	int to;
	int dis;
	int ch;
	bool (operator < (const state &other) const)
	{
		return (dis > other.dis);
	}
	
} state;

vector <state> edge[maxN];
map <string, int> map1; 
int pa[maxN];
int ch[maxN][maxN];
int m;
int dis[4005][27];

void init()
{
	map1.clear();
	for (int i = 0; i < maxN; i++) edge[i].clear();
	for (int i = 0; i < 4005; i++)
		for (int j = 0; j < 27; j++) dis[i][j] = inf;
}

void xuly()
{
	for (int i = 0; i <= 26; i++) dis[0][i] = 0;
	priority_queue < state > pq; 
	state t;
	t.to = 0;
	t.dis = 0;
	t.ch = 26;
	pq.push(t);
	bool ok = false;
	while (!pq.empty())
	{
		state front = pq.top();
		pq.pop();
		//cout << front.to << endl;
		if (front.to == 1) 
		{
			ok = true; 
			cout << front.dis << endl;
			break;
		}
		if (dis[front.to][front.ch] != front.dis) continue;
		for (int i = 0; i < edge[front.to].size(); i++)
		{
			state v = edge[front.to][i];
			if (front.ch != v.ch && front.dis + v.dis < dis[v.to][v.ch])
			{
				dis[v.to][v.ch] = t.dis = dis[front.to][front.ch] + v.dis;
				t.to = v.to;
				t.ch = v.ch;
				pq.push(t);
			}
		}
	}
	if (!ok) cout << "impossivel" << endl; 
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	int n;
	while (cin >> n)
	{
		if (n == 0) break;
		init();
		string s, ss, r;
		cin >> s >> ss;
		map1[s] = 0;
		map1[ss] = 1;
		m = 2;
		for (int i = 0; i < n; i++)
		{
			cin >> s >> ss >> r;
			state t;
			if (map1.find(s) == map1.end())
			{
				map1[s] = m;
				m++;
			}
			if (map1.find(ss) == map1.end())
			{
				map1[ss] = m;
				m++;
			}
			t.to = map1[s];
			t.dis = r.size();
			t.ch = r[0] - 'a';
			edge[map1[ss]].push_back(state (t));
			t.to = map1[ss];
			edge[map1[s]].push_back(state (t));
		}
		xuly();
	}
}

