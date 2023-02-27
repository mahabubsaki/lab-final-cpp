#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dq.push_back(x);
    }

    while (dq.size())
    {
        if (dq.front() > dq.back())
        {
            cout << dq.back() << " ";
            dq.pop_back();
        }
        else
        {
            cout << dq.front() << " ";
            dq.pop_front();
        }
    }

    return 0;
}