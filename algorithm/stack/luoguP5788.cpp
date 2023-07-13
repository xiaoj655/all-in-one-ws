#include<iostream>
#include<stack>
using namespace std;

const int N = 3100000;
unsigned arr[N],ans[N];
stack<int> st;
int main() {
  int n;cin >> n;
  for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
  for(int i=n;i>0;i--){
    while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
    if(st.empty()) ans[i] = 0;
    else ans[i] = st.top();
    st.push(i);
  }
  for(int i=1;i<n;i++){
    printf("%d ", ans[i]);
  }
  printf("%d", ans[n]);
}
