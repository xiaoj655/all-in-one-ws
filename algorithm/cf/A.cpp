#include<bits/stdc++.h>

using namespace std;

int main(){
  int T;cin >> T;
  while(T--){
    int m,n;cin>>m>>n;
    if(m>=2) cout << 1;
    else if(m==1 && n==2) cout << 3;
    else cout << 2;
    cout << '\n';
  }
}
