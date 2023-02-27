#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mp;
    int n;
    cin >> n;
    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        string cur;
        cin >> cur;
        mp[cur] == 0 ? result.push_back(-1) : result.push_back(mp[cur] - 1);
        mp[cur] = i + 1;
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}