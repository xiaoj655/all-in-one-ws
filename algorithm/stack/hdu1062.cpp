// Text Reverse

#include<bits/stdc++.h>

using namespace std;

stack<char> st;
int main () {
  while(true){
    char x = getchar();
    if(x==' '){
      while(!st.empty()){
        cout << st.top();
        st.pop();
      }
      cout << ' ';
    }else if(x == '\n'||x == EOF) break;
    else {
      st.push(x);
    }
  }
  while(!st.empty()){
    cout << st.top();
    st.pop();
  }
}
