#include<bits/stdc++.h>

using namespace std;

const int N = 100010;
int arr[N],ans[N];
stack<int> st;
int main() {
  int n;cin >> n;
  for(int i=1;i<=n;i++) cin >> arr[i];
  for(int i=n;i>0;i--){
    while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
    if(st.empty()) ans[i] = 0;
    else ans[i] = st.top();
    st.push(i);
  }
  for(int i=1;i<n;i++){
    cout << ans[i] << '\n';
  }
  cout << ans[n];
}
