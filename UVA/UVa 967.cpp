#include <bits/stdc++.h>
using namespace std;

int ff[55]={3,7,11,13,17,31,37,71,73,79,97,113,131,197,199,311,337,373,719,733,919,971,991,1193,1931,3119,3779,7793,7937,9311,9377,11939,19391,19937,37199,39119,71993,91193,93719,93911,99371,193939,199933,319993,331999,391939,393919,919393,933199,939193,939391,993319,999331};

main(){
	int a, b;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	while (scanf("%d", &a) && a != -1)
	{
		scanf("%d", &b);
		int ans = 0;
		int x = lower_bound(ff, ff+55, a) - ff;
		for (int i = x-1; i < 55; i++)
			if (a <= ff[i] && ff[i] <= b) ans++; else if (ff[i] > b) break;
		if (ans == 0) printf("No Circular Primes.\n"); else
		if (ans == 1) printf("1 Circular Prime.\n"); else 
		printf("%d Circular Primes.\n", ans);
	}
}
