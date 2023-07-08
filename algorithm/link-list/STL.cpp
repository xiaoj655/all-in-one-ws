#include<bits/stdc++.h>

using namespace std;

list<int> node;

int main(){
  int m,n;cin >> m >> n;
  for(int i=1;i<=m;i++){
    node.push_back(i);
  }
  list<int>::iterator it = node.begin();
  while((m--) > 1) {
    for(int i=1;i<n;i++){
      it++;
      if(it == node.end()) it = node.begin();
    }
    cout << *it << ' ';
    it = node.erase(it);
    if(it == node.end()) it = node.begin();
  }
  cout << *it;
}
