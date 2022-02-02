#include <iostream>
using namespace std;
struct Node
{
    Node *next;
    Node *prev;
    int data;
    Node(const int num)
    {
        data = num;
        prev = next = nullptr;
    }
};
class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyLinkedList() // constructor
    {
        head = tail = nullptr;
    }
    ~DoublyLinkedList() // Destructor
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
        if (tail == head && tail == nullptr)
        {
            head = tail = newNode;
            head->prev = tail->next = nullptr;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            tail->next = nullptr;
        }
    }
    void insertFront(const int num)
    {
        // Write code to insert at head
        Node *newNode = new Node(num);
        //newNode->next = head;
        if (tail == head && tail == nullptr)
        {
            head = tail = newNode;
            head->prev = tail->next = nullptr;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            head->prev = nullptr;
        }
    }
    int removeFront()
    {
        Node *temp = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        int data = temp->data;
        delete temp;
        return data;
    }
    bool remove(const int num)
    {
        // remove a value if it exsists
        Node *curr = head;
        while (curr && curr->data != num)
        {
            curr = curr->next;
        }
        if (!curr)
            return false;
        if (curr == head && curr == tail)
            head = tail = nullptr;
        else if (curr == head)
        {
            head = head->next;
            head->prev = nullptr;
        }
        else if (curr == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            curr->next->prev = curr->prev;
            curr->prev->next = curr->next;
        }
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
};
int main(int argc, const char *argv[])
{
    DoublyLinkedList linkedlist;
    int n = 0;
    cout << "Enter two numbers to insert at front : ";
    cin >> n;
    linkedlist.insertFront(n);
    cin >> n;
    linkedlist.insertFront(n);
    cout << "Enter two numbers to insert at end: ";
    cin >> n;
    linkedlist.insert(n);
    cin >> n;
    linkedlist.insert(n);
    linkedlist.printAll();
    cout << "Enter a number to search in the linked list : ";
    cin >> n;
    if (linkedlist.search(n))
        cout << "Number found in the linked list" << endl;
    else
        cout << "Number not found in the linked list" << endl;
    cout << "Enter a number to delete from linked list : ";
    cin >> n;
    if (linkedlist.remove(n))
        cout << "Number has been deleted from the linked list" << endl;
    else
        cout << "Unable to delete number from the linked list - Number Does not exist in the linked list"<< endl;
                linkedlist.printAll();
    cout << "Removing Front Element" << endl;
    cout << "Front value of the linked list : " << linkedlist.removeFront() << endl;
    linkedlist.printAll();
    return 0;
}