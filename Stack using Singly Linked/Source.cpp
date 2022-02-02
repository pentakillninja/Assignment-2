#include <iostream>
using namespace std;
struct Node
{
    Node *next;
    int data;
    Node(const int num)
    {
        data = num;
        next = nullptr;
    }
};
class SinglyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    SinglyLinkedList() // constructor
    {
        head = tail = nullptr;
    }
    ~SinglyLinkedList() // Destructor
    {
        Node *curr = head;
        while (curr)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
    void insert(const int num)
    {
        //Write code to insert a value at the end
        Node *newNode = new Node(num);
        if (head == tail && head == nullptr)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insertFront(const int num)
    {
        // Write code to insert at head
        Node *newNode = new Node(num);
        if (!head)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    int removeFront()
    {
        Node *curr = head;
        if (head == tail)
            head = tail = nullptr;
        else
            head = head->next;
        int data = curr->data;
        delete curr;
        return data;
    }
    bool remove(const int num)
    {
        // remove a value if it exsists
        Node *prev = nullptr, *curr = head;
        while (curr && curr->data != num)
        {
            prev = curr;
            curr = curr->next;
        }
        if (!curr)
            return false;
        if (curr == head && curr == tail)
            head = tail = nullptr;
        else if (curr == head)
            head = head->next;
        else if (curr == tail)
        {
            tail = prev;
            tail->next = nullptr;
        }
        else
            prev->next = curr->next;
        delete curr;
        return true;
    }
    bool search(const int num) const
    {
        // search for a value
        Node *temp = head;
        while (temp)
        {
            if (temp->data == num)
                return true;
            temp = temp->next;
        }
        return false;
    }
    void printAll() const
    {
        // print all values in linkedlist
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    bool isEmpty()
    {
        return !head;
    }
};
class Stack
{
    SinglyLinkedList list;

public:
    bool isEmpty()
    {
        return list.isEmpty();
    }
    bool isFull()
    {
        return false;
    }
    void push(int data)
    {
        list.insertFront(data);
    }
    bool pop(int &output)
    {
        if (!isEmpty())
        {
            output = list.removeFront();
            return true;
        }
        return false;
    }
};
int main()
{
    Stack s;
    int n = 0;
    while (n != -1)
    {
        if (!s.isFull())
        {
            cout << "Enter a number : ";
            cin >> n;
            s.push(n);
        }
        else
        {
            cout << "Stack is full!";
            break;
        }
    }
    while (!s.isEmpty())
    {
        int temp = 0;
        s.pop(temp);
        cout << temp << " ";
    }
    cout << endl;
    return 0;
}
