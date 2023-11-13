#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  string convert(string s, int numRows)
  {
    vector<string> str(numRows);
    int n = s.size();
    int flag = 1;
    int curRow = 0;
    for (int i = 0; i < n; i++)
    {
      str[curRow].push_back(s[i]);
      curRow += flag;
      if (curRow == 0 || curRow == numRows - 1)
        flag = -flag;
    }
    string res;
    for (string s : str)
    {
      res += s;
    }
    return res;
  }
};

int main()
{
  string x = "PAYPALISHIRING";
  cout << Solution().convert(x, 3);
}