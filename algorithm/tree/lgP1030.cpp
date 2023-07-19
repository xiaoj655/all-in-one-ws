#include<bits/stdc++.h>

using namespace std;

string a,b;
void process(string x,string y){
  if(x.length()>0){
    char tar = y[y.length()-1];
    int k = x.find(tar);
    cout << tar;
    process(x.substr(0,k),y.substr(0,k));
    process(x.substr(k+1), y.substr(k,y.length()-k-1));
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin >> a >> b;
  process(a,b);
}
