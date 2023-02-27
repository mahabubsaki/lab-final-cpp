#include <bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 100;
class StaticQueue
{
public:
    int *arr;
    int left;
    int right;
    int size;
    StaticQueue()
    {
        arr = new int[MAX_SIZE];
        left = 0;
        right = -1;
        size = 0;
    }
    void enqueue(int value)
    {

        if (size == MAX_SIZE)
        {
            cout << "Queue is full";
            return;
        }
        right++;
        size++;
        arr[right] = value;
    }
    void dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty";
            return;
        }
        left++;
        size--;
    }
    int front()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[left];
    }
};
int main()
{
    StaticQueue q;
    q.enqueue(2);
    q.enqueue(10);
    q.enqueue(100);
    q.enqueue(1000);
    q.enqueue(10000);
    q.dequeue();
    cout << q.front();
    return 0;
}