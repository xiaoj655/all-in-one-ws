#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  priority_queue<int, vector<int>, greater<int>> q;
  int n;cin>>n;
  while(n--){
    int op;cin>>op;
    if(op==1){
      int x ;std::cin >> x;
      q.push(x);
    }else if(op==2){
      cout << q.top() << endl;
    }else {
      q.pop();
    }
  }
}

























// const int N = 1e6+5;
// int heap[N], len=0;
// 
// void push(int x){
//   heap[++len]=x;
//   int i=len;
//   while(i>1 && heap[i]<heap[i/2]){
//     swap(heap[i], heap[i/2]);
//     i/=2;
//   }
// }
// 
// void pop(){
//   heap[1] = heap[len--];
//   int i=1;
//   while(i*2 <= len){
//     int son=2*i;
//     if(son < len && heap[son]>heap[son+1]) ++son;
//     if(heap[son]<heap[i]){
//       swap(heap[son],heap[i]);
//       i=son;
//     } else { break; }
//   }
// }
// 
// int main(){
//   int T;cin >> T;
//   while(T--){
//     int op;cin >> op;
//     if(op == 1){
//       int x;cin >> x;
//       push(x);
//     }else if(op == 2){
//       cout << heap[1] << endl;
//     }else{
//       pop();
//     }
//   }
//   return 0;
// }
