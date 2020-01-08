#include <bits/stdc++.h>
#define inf (int) (1e9+7)
#define vi vector <int>
using namespace std;

int cur_time = inf;
string line;
int test = 0, n;
vi ti;

bool allgreen(int t, vi ti)
{
	for (int i = 0; i < ti.size(); i++)
	{
		if ((t % (2*ti[i])) >= (ti[i] - 5)) return false;
	}
	return true;
}

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	while (getline(cin, line))
	{
		test++;
		stringstream ss(line);
		cur_time = 90;
		while (ss >> n)
		{
			ti.push_back(n);
			cur_time = min(cur_time, n);
		}
		cur_time *= 2;
		while(!allgreen(cur_time, ti) && cur_time <= 3600) cur_time++;
		if (cur_time > 3600)
		{
			cout << "Set " << test << " is unable to synch after one hour." << endl;
		} 
		else
		{
			cout << "Set " << test << " synchs again at " << cur_time / 60 << " minute(s) and " << cur_time % 60 << " second(s) after all turning green." << endl;
		}
		ti.clear();
	}
}
