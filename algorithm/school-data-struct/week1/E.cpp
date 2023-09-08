#include<iostream>
using namespace std;

void process_I(int* arr, int length){
  int sum=0;
  for(int i=0;i<length;i++){
    sum += *(arr+i);
  }
  cout << sum/length << '\n';
}
void process_C(char* arr, int length){
  char max= *arr;
  for(int i=1;i<length;i++){
    if(max < *(arr+i)) max=*(arr+i);
  }
  cout << max << '\n';
}
void process_F(double* arr, int length){
  double min=0x7fffffff;
  for(int i=0;i<length;i++){
    if(min > *(arr+i)) min = *(arr+i);
  }
  cout << min << '\n';
}
int main(){
  int T;cin >> T;
  while(T--){
    char x;cin >>x;
    int n; cin >> n;
    int* arr = nullptr;
    char* arr_c = nullptr;
    double* arr_d = nullptr;
    if(x =='I'){ 
      arr = new int[n];
      for(int i=0;i<n;i++) cin >> arr[i];
    }
    else if(x == 'F'){
      arr_d = new double[n];
      for(int i=0;i<n;i++) cin >> arr_d[i];
    }
    else if(x == 'C'){ 
      arr_c = new char[n];
      for(int i=0;i<n;i++) cin >> arr_c[i];
    }
    switch (x)
    {
    case 'I':
      process_I(arr,n);
      break;
    case 'C':
      process_C(arr_c,n);
      break;
    case 'F':
      process_F(arr_d,n);
      break;
    default:
      break;
    }
    delete[] arr;
  }
}