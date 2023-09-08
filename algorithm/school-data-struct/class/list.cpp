const int MAX_LEN = 1111;
int a[MAX_LEN];
int length;

int Insert_1(int a[], int ith, int b){
  if(length+1 >= MAX_LEN) return -1;
  for(int i=length-1;i>=ith;i--){
    a[i+1]=a[i];
  }
  a[ith] = b;
  return 0;
}