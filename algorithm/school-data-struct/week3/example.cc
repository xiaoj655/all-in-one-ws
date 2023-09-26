#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isOp(char x)
{
  return x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')';
}

string reverse(string x)
{
  stack<string> con;
  string res = "";
  int ptr1 = 0, ptr2 = 0;
  for (; ptr2 < x.size(); ptr2++)
  {
    if (isOp(x[ptr2]))
    {
      string x1 = x.substr(ptr1, ptr2 - ptr1);
      string x2 = x.substr(ptr2, 1);
      ptr1 = ptr2 + 1;

      con.push(x1);
      con.push(x2);
    }
  }
  string x1 = x.substr(ptr1, ptr2 - ptr1);
  con.push(x1);

  while (!con.empty())
  {
    string tem = con.top();
    if (tem == "(")
      tem = ")";
    else if (tem == ")")
      tem = "(";
    res.append(tem);
    con.pop();
  }
  return res;
}

int main()
{
  string x = "(1+2)*(10+999)/321";
  cout << reverse(x);
}