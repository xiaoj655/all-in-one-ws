#include<bits/stdc++.h>

using namespace std;

#define N 1005
struct myqueue {
  int* data;
  int rear,head;

  bool init() {
    data = new int[N];
    if(!data) return false;
    rear =0;
    head =0;
    return true;
  }

  int size(){
    return (rear - head) % N;
  }

  bool push(int a){
    data[rear++] = a;
    if(data[rear-1]) return true;
    return false;
  }

  int pop(){
    return data[head++];
  }

  bool front(){
    return data[head];
  }
}Q;

int Hash[1005];
int cnt;
int main() {
  Q.init();
  int m,n;cin >> m >> n;
  while(n--){
    int en;cin >> en;
    while(!Hash[en]){
      cnt++;
      Hash[en] = 1;
      Q.push(en);
      while(Q.size() > m){
        Hash[Q.pop()] = 0;
      }
    }
  }
  cout << cnt;
}

// queue<int> que;
// int Hash[1005];
// int main () {
//   int m,n;cin>>m>>n;
//   int cnt=0;
//   while(n--){
//     int en;cin >> en;
//     if(!Hash[en]){
//       ++cnt;
//       Hash[en] = 1;
//       que.push(en);
//       while(que.size() > m){
//         Hash[que.front()] = 0;
//         que.pop();
//       }
//     }
//   }
//   cout << cnt;
// }
