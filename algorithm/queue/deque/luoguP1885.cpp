#include<bits/stdc++.h>
using namespace std;

deque<int> dq;

int arr[1000000+10];

int main () {
  int m,k;cin >> m >> k;
  for(int i=0;i<m;i++){
    cin >> arr[i];
  }
  for(int i=0;i<m;i++){
    while(!dq.empty() && dq.front()<=i-k) dq.pop_front();
    while(!dq.empty() && arr[i]<arr[dq.back()]) dq.pop_back();
    dq.push_back(i);
    if(i>=k-1){
      cout << arr[dq.front()] << ' ';
    }
  }
  cout << endl;
  while(!dq.empty()) dq.pop_back();
  for(int i=0;i<m;i++){
    while(!dq.empty() && dq.front()<=i-k) dq.pop_front();
    while(!dq.empty() && arr[i]>arr[dq.back()]) dq.pop_back();
    dq.push_back(i);
    if(i>=k-1){
      cout << arr[dq.front()] << ' ';
    }
  }
}
