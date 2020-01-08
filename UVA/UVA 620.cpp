#include <bits/stdc++.h>
using namespace std;

int backtrack(int start, int end)
{
	if (start == end && s[start] == "A") return 0;
	if (s[start] == "A" && s[end] == "B")
		if (start == end + 1) return 1;
		else if (backtrack(start+1, end-1) != 0) return 3; else return 1;
	if (start == end )
			
}

main(){
	scanf("%d", &n);
	while (n--)
	{
		gets(s);
		ans = backtrack(0, s.size() - 1);
		switch(ans)
		case 0: printf("SIMPLE\n"); break;
		case 1: printf("FULLY-GROWN\n"); break;
		case 2: printf("MUTAGENIC\n"); break;
		case 3: printf("MUTANT\n"); break;
	}
}
