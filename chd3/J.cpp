#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	long long  a[6];
	float m;
    ll num[6];
	while (cin >> m) {
		m*=1000;
		a[0]=floor(m);
        for (int i=1; i<6; i++) 
		{
			cin >> m;
			m*=1000;
			a[i]=floor(m);
		}
		/*for (int i=0; i<6; i++) {
			string s=a[i];
			if (s.find(".")!=string::npos) {
				while (s.find(".")!=s.size()-4) s=s+"0";
			} else s=s+".000";
			a[i]=s;
		}
        for (int i=0; i<6; i++) {
			num[i]=0;
			string ss=a[i];
            for (int j=0; j<ss.size(); j++) {
				if ((48<=int(ss[j]))&&(int(ss[j])<=57)) num[i]=num[i]*10+int(ss[j])-48;
			}
		}*/
		
		ll x1=a[0]-a[2],x2=a[2]-a[4],y1=a[1]-a[3],y2=a[3]-a[5];
		ll d=abs(x1*y2-x2*y1);
        double dd=d/2e6;
        cout << setprecision(15)<<fixed<< dd <<endl;
        /*if (r==0) cout << "0"; else cout << "5";
        int sp;
        if (dd%1000000==0) sp=1; else sp=(int)log10(dd%1000000)+1;
        for (int i=0; i<15-(sp+1); i++) cout << "0"; cout << endl;*/
	}
}
