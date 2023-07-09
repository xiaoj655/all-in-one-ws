#include<iostream>

using namespace std;

int main() {
  int T;cin >> T;
  int t=T;
  while(T--){
    int n;cin >> n;
    int max = -0x7777777;
    int sum=0;
    int s=1,e=0;
    for(int i=1;i<=n;i++){
      int x;cin >> x;
      sum += x;
      if(sum > max){
        e = i;
        max = sum;
      }
      if(sum<0) {
        s = i+1;
        sum = 0;
      }
    }
    if(s > e) s = e;
    cout << "Case " << t-T << ":" << endl;
    cout << max << ' '<<s << ' ' << e <<'\n';
    if(T!=0)cout<<endl;
  }
}
