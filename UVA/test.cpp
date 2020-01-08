#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(){
 long n,tmp;
 char str[100000];
 bool f;

 //freopen("i.txt","r",stdin);

 while( gets(str) ){
  stacksum,val;
  char * token = strtok(str," ");
  f = true;
  while( token ){
   n = atoi(token);
   if( n < 0){
    val.push(n * (-1));
    sum.push(0);
   }
   else{
    if( val.empty() ){
     f = false;
     cout << 1 << endl;
     break;
    }
    tmp = val.top();
    val.pop();
    if( tmp != n ){
     f = false;
     cout << 2 << endl;
     break;
    }

    tmp = sum.top();
    sum.pop();
    if(tmp >= n){
     f = false;
     break;
     cout << 3 << endl; 
    }
    if( !sum.empty()){
     tmp = sum.top();
     sum.pop();
     tmp += n;
     sum.push(tmp);
    }
   }
   token = strtok(NULL," ");
  }
  if(f && val.empty())
   printf(":-) Matrioshka!\n");
  else
   printf(":-( Try again.\n");
 }

 return 0;
}
