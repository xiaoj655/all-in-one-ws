#include<iostream>
using namespace std;

int main(){
  const char* title[] = {"January","February","March","April","May","June","July","Aguest","September","October","November","December"};
  int t;cin>>t;
  while(t--){
    int a;cin>>a;
    if(a<=12 && a>=1) 
    cout << title[a-1] << '\n';
    else cout << "error\n";
  }
}