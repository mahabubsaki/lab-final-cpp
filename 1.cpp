#include <bits/stdc++.h>
using namespace std;
vector<string> merge_sort(vector<string> a)
{
    if (a.size() <= 1)
    {
        return a;
    }
    int middle = a.size() / 2;
    vector<string> b;
    vector<string> c;
    for (int i = 0; i < middle; i++)
    {
        b.push_back(a[i]);
    }
    for (int i = middle; i < a.size(); i++)
    {
        c.push_back(a[i]);
    }
    vector<string> sorted_b = merge_sort(b);
    vector<string> sorted_c = merge_sort(c);

    vector<string> sorted_a;
    int idx1 = 0;
    int idx2 = 0;
    int size = a.size();
    for (int i = 0; i < size; i++)
    {
        if (idx1 == sorted_b.size())
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
        else if (idx2 == sorted_c.size())
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else if (sorted_b[idx1][0] < sorted_c[idx2][0])
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
    };
    return sorted_a;
};

int main()
{
    int size;
    cin >> size;
    vector<string> a(size);
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    vector<string> ans = merge_sort(a);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    };

    return 0;
}