#include<iostream>
using namespace std;

int arr[2][3];
void roate(){
  for(int i=2;i>=0;i--){
    for(int k=0;k<2;k++){
      cout << arr[k][i] << ' ';
    }
    cout << '\n';
  }
}
int main(){
  int T;cin >> T;
  while(T--){
    for(int i=0;i<2;i++){
      for(int k=0;k<3;k++){
        cin >> arr[i][k];
      }
    }
    roate();
  }
}