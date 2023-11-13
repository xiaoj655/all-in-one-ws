#include <iostream>
#include <vector>
using namespace std;

void createArr(int len)
{
  vector<int> v = {5, 8};
  cout << "5 8 ";
  int a = 9;
  for (int i = 0; i < len - 2; i++)
  {
    while (++a * 3 % (v[i] + v[i + 1]) != 0)
    {
    }
    v.push_back(a);
    cout << a << ' ';
  }
  cout << '\n';
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int len;
    cin >> len;
    createArr(len);
  }
  return 0;
}