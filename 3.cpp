#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *previous;
    Node *next;
};
class LinkedList
{
public:
    Node *head;
    Node *tail;
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }
    Node *CreateNode(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->previous = nullptr;
        return newNode;
    }
    void insertHead(int value)
    {
        Node *newNode = CreateNode(value);
        if (!head)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
    }
    void insertTail(int value)
    {
        Node *newNode = CreateNode(value);
        if (!tail)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    void insertMid(int value)
    {
        // checking corner case : if head is not available so we inserting into head;
        if (!head)
        {
            insertHead(value);
            return;
        }
        // checking corner case : if there is only one element on the list. so we inserting as second element of the list
        if (!head->next)
        {
            insertTail(value);
            return;
        }
        Node *newNode = CreateNode(value);
        Node *start = head;
        Node *end = tail;
        while (start->next != end && end->previous != start)
        {
            start = start->next;
            end = end->previous;
            if (start == end)
            {
                start = start->previous;
                break;
            }
        }
        start->next = newNode;
        newNode->previous = start;
        end->previous = newNode;
        newNode->next = end;
    }
    void print()
    {
        Node *current = head;
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    void Merge(LinkedList a)
    {
        // checking if the parameter a have any element
        if (a.head)
        {
            Node *currentTail = tail;
            currentTail->next = a.head;
            tail = a.tail;
        }
    }
};
int main()
{
    LinkedList a;
    LinkedList b;

    a.insertHead(1);
    a.insertTail(5);
    a.insertMid(3);
    a.insertHead(0);
    a.insertTail(10);
    a.print(); // prints  0 1 3 5 10

    b.insertHead(10);
    b.insertTail(50);
    b.insertMid(30);
    b.insertHead(9);
    b.insertTail(100);
    b.print(); // prints  9 10 30 50 100

    a.Merge(b);
    a.print(); // prints  0 1 3 5 10 9 10 30 50 100
    b.print(); // prints  9 10 30 50 100
}
