#include<bits/stdc++.h>

using namespace std;

stack<char> dat, op;

int check(char x) {
  switch (x) {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '^': return 3;
    case ')': return 0;
    case '(': return 0;
    default: return -1;
  }
}
int cal(char a, char b,char op){
  switch(op){
    case '+': return static_cast<int>(a)-96+static_cast<int>(b);
    case '-': return static_cast<int>(a)-96-static_cast<int>(b);
    case '/': return (static_cast<int>(a)-96)/(static_cast<int>(b)-96);
    case '*': return (static_cast<int>(a)-96)*(static_cast<int>(b)-96);
  }
  return 0;
}

bool isop(char x){
  if(x =='+' || x=='-' || x=='*' || x=='/') return true;
  return false;
}
void say(char* res){
  int cnt=0;
  while(res[cnt] != 0){
    if(res[cnt] == '0') continue;
    cout<<res[cnt];
    cnt++;
  }
  cout<<'\n';
}

void process(char* res,int& i){
  res[i-2] = cal(res[i-2],res[i-1],res[i]);
  res[i-1] = '0';
  res[i] = '0';
  say(res);
}

int main() {
  string str; cin >> str;
  char* res;
  int cnt = 0;
  while(str[cnt] != '\0'){
    char tar = str[cnt];
    if(isdigit(tar)) dat.push(tar);
    else if(tar == '('){
      op.push(tar);
    } else if(tar == ')') {
      char x = op.top();
      while(x!='('){
        dat.push(x);
        op.pop();
        x = op.top();
      }
      op.pop();
    } else if(check(tar)>-1 && check(tar)<4){
      while(!op.empty() && check(op.top()) > check(tar)) {
        dat.push(op.top());
        op.pop();
      }
      op.push(tar);
    }
    cnt++;
  }
  while(!op.empty()){
    dat.push(op.top());
    op.pop();
  }
  while(!dat.empty()){
    op.push(dat.top());
    dat.pop();
  }
  int cnt2=0;
  res = new char[cnt+10];
  while(!op.empty()){
    res[cnt2++] = op.top();
    op.pop();
  }
  res[cnt] = '\0';
  for(int i=0;i<cnt2;i++){
    if(isop(res[i])){
      process(res,i);
    }
  }
}
