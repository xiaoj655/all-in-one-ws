#include<bits/stdc++.h>

using namespace std;

string str;

void maketree(int l,int r){
  if(l<r){
    maketree(l,(r+l)>>1);
    maketree((r+l)/2+1,r);
  }
  bool B=false,I=false;
  for(int i=l;i<=r;i++){
    if(str[i] == '0') B = true;
    else if(str[i] == '1') I = true;
    if (B && I) break;
  }
  if(B&&I) cout << 'F';
  else if(B) cout << 'B';
  else cout << 'I';
}

int main() {
  int n;
  cin >>n>> str;
  maketree(0,(1<<n)-1);
  return 0;
}

// char str[2000];
// 
// void maketree(int r, int l){
//   if(l>r){
//     maketree(r,(r+l)>>1);
//     maketree((r+l+1)>>1,l);
//   }
//   int B=0,I=0;
//   for(int i=r;i<=l;i++){
//     if(str[i] == '0') B=1;
//     else if(str[i] == '1') I=1;
//     if(B && I) break;
//   }
//   if(B&&I) printf("F");
//   else if(B) printf("B");
//   else printf("I");
// }
// int main() {
//   int n;
//   scanf("%d %s",&n,&str);
//   maketree(0,(1<<n)-1);
//   return 0;
// }
