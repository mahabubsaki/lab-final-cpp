#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<int> mySet;
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int x;
        cin >> x;
        mySet.insert(x);
    }
    int b;
    cin >> b;
    for (int i = 0; i < b; i++)
    {
        int x;
        cin >> x;
        mySet.insert(x);
    }
    for (auto i = mySet.begin(); i != mySet.end(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}