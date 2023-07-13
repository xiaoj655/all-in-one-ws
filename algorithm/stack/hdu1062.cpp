// Text Reverse

#include<bits/stdc++.h>

using namespace std;

const int N = 10010;
struct mystack {
  char* st;
  int cnt;
  void init() { st = new char[N]; cnt = 0;}
  void push(char x){ st[++cnt]=x; }
  char top(){return st[cnt];}
  void pop(){ --cnt; }
  bool empty(){
    if(cnt == 0) return true;
    else return false;
  }
}a;
int main(){
  a.init();
  while(true){
    char x; x= getchar();
    if(x == ' '){
      while(!a.empty()){
        cout << a.top();
        a.pop();
      }
      cout << ' ';
    } else if(x=='\n'||x==EOF){
      break;
    } else {
      a.push(x);
    }
  }
  while(!a.empty()){
    cout << a.top();
    a.pop();
  }
}
// stack<char> st;
// int main () {
//   while(true){
//     char x = getchar();
//     if(x==' '){
//       while(!st.empty()){
//         cout << st.top();
//         st.pop();
//       }
//       cout << ' ';
//     }else if(x == '\n'||x == EOF) break;
//     else {
//       st.push(x);
//     }
//   }
//   while(!st.empty()){
//     cout << st.top();
//     st.pop();
//   }
// }
