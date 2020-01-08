#include <bits/stdc++.h>
#define vi vector <int>
using namespace std;

vi f;
vi ff, nxt;
bool used[10];
int n;

void init()
{
	nxt.push_back(0);
	for (int i = 0; i < 9; i++)
	{
		ff = nxt;
		nxt.clear();
		for (int j = 0; j < ff.size(); j++)
		{
			int num = ff[j];
			fill(used, used+10, false);
			while (num)
			{
				used[num % 10] = true;
				num /= 10;
			}
			
			for (int k = 1; k < 10; k++)
			{
				if (!used[k]) 
				{
					nxt.push_back(ff[j] * 10 + k);
					f.push_back(ff[j] * 10 + k);
				}
			}
		}
	}
}

main(){
	init();
	sort(f.begin(), f.end());
	//cout << f.size() << endl;
	while(cin >> n)
	{
		if (n >= 987654321) cout << "0" << endl; else cout << *(upper_bound(f.begin(), f.end(), n)) << endl;
	}
}
