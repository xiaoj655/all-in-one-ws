#include<bits/stdc++.h>

using namespace std;


int cal(char a, char b,char op){
  switch(op){
    case '+': return static_cast<int>(a)+static_cast<int>(b);
    case '-': return static_cast<int>(a)-static_cast<int>(b);
    case '/': return static_cast<int>(a)/static_cast<int>(b);
    case '*': return static_cast<int>(a)*static_cast<int>(b);
  }
  return 0;
}

int main(){
  char x = '0';
  int a = static_cast<int>(x);
  cout << a;
  }
