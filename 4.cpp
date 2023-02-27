#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    bool isValid = true;
    stack<char> st;
    for (int i = 0; i < str.size(); i++)
    {
        if (st.empty() || str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            st.push(str[i]);
        }
        else
        {
            if (!((st.top() == '(' && str[i] == ')') || (st.top() == '[' && str[i] == ']') || (st.top() == '{' && str[i] == '}')))
            {
                isValid = false;
                break;
            }
            st.pop();
        }
    }
    if (isValid)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}