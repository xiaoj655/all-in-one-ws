#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int k, tar;
    cin >> k >> tar;
    int tem;
    bool flag = false;
    while (k--)
    {
      cin >> tem;
      if (tem == tar)
      {
        flag = true;
      }
    }
    if (!flag)
    {
      cout << "NO\n";
    }
    else
    {
      cout << "YES\n";
    }
  }
  return 0;
}