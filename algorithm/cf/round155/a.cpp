#include <iostream>
using namespace std;

int fun(int x)
{
  if (x == 1 || x == 0)
    return 1;
  return fun(x - 1) * x;
}
int *calS(string s, char tar)
{
  int cnt = 0;
  int res = 0;
  int res2 = 1;
  int *arr = new int[2];
  for (char x : s)
  {
    if (tar == x)
    {
      cnt++;
    }
    else
    {
      if (cnt >= 2)
      {
        res += cnt - 1;
        res2 *= fun(cnt);
      }
      cnt = 0;
    }
  }
  if (cnt >= 2)
  {
    res += cnt - 1;
    res2 *= fun(cnt);
  }
  arr[0] = res;
  arr[1] = res2;
  return arr;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    string s;
    cin >> s;
    int *res1 = calS(s, '0');
    int *res2 = calS(s, '1');
    cout << res1[0] + res2[0] << ' ' << res1[1] * res2[1];
    cout << '\n';
  }
  return 0;
}