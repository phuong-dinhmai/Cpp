#include <stdio.h>
main(){
    long long n;
    while (scanf("%lld",&n)>0)
    {
        if (n%8==1) printf("1\n");
        if ((n%8==2) || (n%8==0)) printf ("2\n");
        if ((n%8==3) || (n%8==7)) printf ("3\n");
        if ((n%8==4) || (n%8==6)) printf ("4\n");
        if (n%8==5) printf ("5\n");
    }
}
