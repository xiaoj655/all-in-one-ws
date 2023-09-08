#include<iostream>
using namespace std;

int main(){
  int T;
  cin >> T;
  while(T--){
    int n;cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int mid=n/2;
    cout << arr[mid-1] << ' ' << arr[mid+1] << '\n';
    int x;cin >> x;
    int gap = x-mid-1;
    if(gap>0){
      for(int i=0;i<gap;i++) ++mid;
    }else if(gap <0){
      for(int i=0;i<abs(gap);i++) --mid;
    }
    cout << arr[mid] << '\n';
  }
}