#include<iostream>
using namespace std;

int main(){
  int t;cin >> t;
  while(t--){
    int n;cin >> n;
    int* arr = new int[n];
    for(int i=0;i<n;i++)cin >> arr[i];
    int* mid = &arr[n/2];
    cout << *(--mid) << ' ' << *(++(++mid));
    --mid;
    int x;cin >>x;
    int gap=x-(n/2)-1;
    if(gap>0){
      for(int i=0;i<gap;i++) ++mid;
    }else if(gap < 0) {
      for(int i=0;i<abs(gap);i++)
    }
  }
}