#include<bits/stdc++.h>

using namespace std;
int main(){
  int T;cin >> T;
  while(T--){
    int m,n,k;cin >> m >> n>>k;
    int x,y;cin >> x >> y;
    string ans = "YES\n";
    while(k--){
      int xx,yy;cin >> xx >> yy;
      if((x+y)%2 == (xx+yy)%2) ans = "NO\n";
    }
    cout << ans;
  }
}
