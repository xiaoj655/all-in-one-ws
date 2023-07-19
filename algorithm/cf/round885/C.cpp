#include<bits/stdc++.h>

using namespace std;

int process(int a, int b){
  int gcd = __gcd(a,b);
  a/=gcd;b/=gcd;
  if(a%2 == 0) return 1;
  if(b%2 == 0) return 2;
  return 4;
}
int main(){
  ios_base::sync_with_stdio(false);
  int T;cin>>T;
  while(T--){
    int n;
    cin >> n;
    int *arr1=new int[n];
    int *arr2=new int[n];
    int cert=0;
    bool flag = true;
    for(int i=0;i<n;i++) cin >> arr1[i];
    for(int i=0;i<n;i++){
      cin >> arr2[i];
      if(arr1[i]==0 && arr2[i]==0) continue;
      cert|=process(arr1[i],arr2[i]);
    }
    cout << (__builtin_popcount(cert)<=1? "YES\n":"NO\n");
    delete[] arr1,arr2;
  }
}
