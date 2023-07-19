#include<bits/stdc++.h>

using namespace std;

int main(){
  int T;cin >> T;
  while(T--){
    int n,k; cin >> n >> k;
    vector<int> color(n);
    vector<int> last(k,-1);
    vector<int> step(k),second_step(k);
    for(int i=0;i<n;i++) cin >> color[i];
    for(int i=0;i<n;i++){
      int max=i-last[color[i]-1];
      if(max>step[color[i]-1]){
        second_step[color[i]-1] = step[color[i]-1];
        step[color[i]-1] = max;
      }else if(max>second_step[color[i]-1]){
        second_step[color[i]-1] = max;
      }
      last[color[i]-1] = i;
    }
    for(int i=0;i<k;i++){
      int max=n-last[i];
      if(max>step[i]){
        second_step[i] = step[i];
        step[i] = max;
      }else if(max>second_step[i]){
        second_step[i] = max;
      }
    }
    int ans=0x7fffffff;
    for(int i=0;i<k;i++){
      ans = min(ans,max(second_step[i],(step[i]+1)/2));
    }
    cout << ans-1 << '\n';
  }
}
