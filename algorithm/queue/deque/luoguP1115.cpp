#include<iostream>
#include<deque>
using namespace std;
deque<int> de;
int arr[200009];
int main() {
  int n,m;cin >> n >> m;
  for(int i=1;i<=n;i++) cin >> arr[i];
  for(int i=2;i<=n;i++) arr[i] += arr[i-1];
  int ans = arr[1];
  for(int i=1;i<=n;i++){
    while(!de.empty() && arr[i]<arr[de.back()]) de.pop_back();
    while(!de.empty() && de.front() <= i-m) de.pop_front();
    de.push_back(i);
    if(i>=m){
      ans = max(ans, arr[i]-arr[de.front()]);
    }
  }
  cout << ans;
}
// int main() {
//     int n;cin >> n;
//     int max = -0x7777777;
//     int sum=0;
//     int s=1,e=0;
//     for(int i=1;i<=n;i++){
//       int x;cin >> x;
//       sum += x;
//       if(sum > max){
//         e = i;
//         max = sum;
//       }
//       if(sum<0) {
//         s = i+1;
//         sum = 0;
//       }
//     }
//     if(s > e) s = e;
//     cout << max;
// }


