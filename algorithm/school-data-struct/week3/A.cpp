#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int opPriority(char op)
{
    return op == '+' || op == '-' ? 1 : 2;
}

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

void toPrifix(string x)
{
    string tar = reverse(x);
    stack<string> st, op;
    int ptr1 = 0, ptr2 = 0;
    for (; ptr2 < tar.size(); ptr2++)
    {
        if (isOp(tar[ptr2]))
        {
            string x1 = tar.substr(ptr1, ptr2 - ptr1);
            string x2 = tar.substr(ptr2, 1);
            ptr1 = ptr2 + 1;

            st.push(x1);
            if (x2 == ")")
            {
                while (!op.empty() && op.top()[0] != '(')
                {
                    st.push(op.top());
                    op.pop();
                }
                op.pop();
                continue;
            }
            while (!op.empty() && op.top() != "(" && opPriority(op.top()[0]) > opPriority(x2[0]))
            {
                st.push(op.top());
                op.pop();
            }
            op.push(x2);
        }
    }
    string x1 = tar.substr(ptr1, ptr2 - ptr1);
    st.push(x1);
    while (!op.empty())
    {
        st.push(op.top());
        op.pop();
    }
    while (!st.empty())
    {
        if (st.top().size() == 0)
        {
            while (!st.empty() && st.top().size() == 0)
            {
                st.pop();
            }
            continue;
        }

        cout << st.top();
        st.pop();
        while (!st.empty() && st.top().size() == 0)
        {
            st.pop();
        }
        if (!st.empty())
            cout << ' ';
    }
    cout << '\n';
}

void toSuffix(string x)
{
    vector<string> con;
    vector<string> res;
    int ptr1 = 0, ptr2 = 0;
    stack<string> op;
    for (; ptr2 < x.size(); ptr2++)
    {
        if (isOp(x[ptr2]))
        {
            con.push_back(x.substr(ptr1, ptr2 - ptr1));
            con.push_back(x.substr(ptr2, 1));
            ptr1 = ptr2 + 1;
        }
    }
    con.push_back(x.substr(ptr1, ptr2 - ptr1));
    for (string s : con)
    {
        if (isOp(s[0]))
        {
            if (s[0] == ')')
            {
                while (!op.empty() && op.top()[0] != '(')
                {
                    res.push_back(op.top());
                    op.pop();
                }
                op.pop();
            }
            else
            {
                while (!op.empty() && op.top()[0] != '(' && s[0] != '(' && opPriority(op.top()[0]) >= opPriority(s[0]))
                {
                    res.push_back(op.top());
                    op.pop();
                }
                op.push(s);
            }
        }
        else
        {
            res.push_back(s);
        }
    }
    while (!op.empty())
    {
        res.push_back(op.top());
        op.pop();
    }

    for (int ix = 0; ix < res.size(); ix++)
    {
        string s = res[ix];
        if (s == "")
            continue;
        cout << s;
        if (ix != res.size() - 1)
            cout << ' ';
    }
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string x;
        cin >> x;
        toPrifix(x);
        toSuffix(x);
        cout << '\n';
    }
}