#include <bits/stdc++.h>
using namespace std;
class MaxHeap
{
public:
    vector<int> nodes;
    MaxHeap()
    {
    }
    void up_heapify(int idx)
    {
        while (idx > 0 && nodes[idx] > nodes[(idx - 1) / 2])
        {
            swap(nodes[idx], nodes[(idx - 1) / 2]);
            idx = (idx - 1) / 2;
        }
    }
    void insert(int x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size() - 1);
    }
    void printHeap()
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            cout << nodes[i] << " ";
        }
    }
    void delete_index(int idx)
    {
        if (idx >= nodes.size())
            return;
        swap(nodes[idx], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(idx);
    }
    void down_heapify(int idx)
    {
        while (true)
        {
            int large = idx;
            int left = (2 * idx) + 1;
            int right = (2 * idx) + 2;
            if (left < nodes.size() && nodes[large] < nodes[left])
            {
                large = left;
            }
            if (right < nodes.size() && nodes[large] < nodes[right])
            {
                large = right;
            }
            if (large == idx)
            {
                break;
            }
            swap(nodes[idx], nodes[large]);
            idx = large;
        }
    }
    int getMax()
    {
        if (nodes.empty())
        {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return nodes[0];
    }
};
class MinHeap
{
public:
    MaxHeap mx;
    // if we keep inserting the negetive value of our insert function parameter than minimum value will be on maxheaps node.
    // if we insert 4,40,2,220 then the inserted value will be -4,-40,-2,-220 and the maxheap array will look like this [-2,-40,-4,-220]
    void insert(int x)
    {

        mx.insert(-x);
    }
    // Delete method will be same as maxheap as we are working with index. Not with the value.
    void Delete(int idx)
    {
        mx.delete_index(idx);
    }
    // We already saw that the minimum value will be on maxheaps root as negetive value.So we have to just find it and return its positve value
    int getMin()
    {
        int max_val = mx.getMax();
        if (max_val == -1)
        {
            return -1;
        }
        return -max_val;
    }
};

int main()
{
    MinHeap mh;
    mh.insert(4);
    mh.insert(40);
    mh.insert(2);
    mh.insert(220);
    mh.Delete(0);
    cout << mh.getMin();
    return 0;
}