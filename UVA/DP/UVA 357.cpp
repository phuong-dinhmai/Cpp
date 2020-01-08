#include <bits/stdc++.h>
#define ll unsigned long long 
using namespace std;

int cent[5] = {1, 5, 10, 25, 50};
ll cnt[30002];

void ans()
{
	cnt[0] = 1;
	for (int i = 0; i < 5; i++)
		for (int j = cent[i]; j <= 30000; j++) cnt[j] += cnt[j - cent[i]]; 
}
main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	for (int i = 0; i <= 30000; i++) cnt[i] = 0;
	int m;
	ans();
	while (scanf ("%d", &m) != EOF)
	{
		if (cnt[m] == 1) printf("There is only 1 way to produce %d cents change.\n", m);
		else printf("There are %lld ways to produce %d cents change.\n", cnt[m], m);
	}
}	
