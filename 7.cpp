#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int value;
    node *Left;
    node *Right;
};

class BST
{
public:
    node *root;
    BST()
    {
        root = nullptr;
    }
    node *CreateNode(int value)
    {
        node *newNode = new node;
        newNode->value = value;
        newNode->Left = nullptr;
        newNode->Right = nullptr;
        return newNode;
    }
    void Insert(int value)
    {
        node *newNode = CreateNode(value);
        if (!root)
        {
            root = newNode;
            return;
        }
        queue<node *> q;

        q.push(root);
        while (!q.empty())
        {
            node *start = q.front();
            q.pop();
            if (!start->Left)
            {
                start->Left = newNode;
                return;
            }
            else
            {
                q.push(start->Left);
            }
            if (!start->Right)
            {
                start->Right = newNode;
                return;
            }
            else
            {
                q.push(start->Right);
            }
        }
    }
    bool Search(int value)
    {
        queue<node *> q;

        q.push(root);
        while (!q.empty())
        {
            node *start = q.front();
            q.pop();
            if (start->value == value)
            {
                return true;
            }
            if (start->Left)
            {
                if (start->Left->value == value)
                {
                    return true;
                }
                q.push(start->Left);
            }
            if (start->Right)
            {
                if (start->Right->value == value)
                {
                    return true;
                }
                q.push(start->Right);
            }
        }
        return false;
    }
};
int main()
{
    BST bst;
    bst.Insert(10);
    bst.Insert(20);
    bst.Insert(25);
    bst.Insert(50);
    bst.Insert(8);
    bst.Insert(9);
    cout << bst.Search(10) << "\n"; // 1
    cout << bst.Search(9) << "\n";  // 1
    cout << bst.Search(20) << "\n"; // 1
    cout << bst.Search(60) << "\n"; // 0
    return 0;
};
