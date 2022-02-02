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
};
int main(int argc, const char *argv[])
{
    SinglyLinkedList linkedlist;
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
        cout << "Unable to delete number from the linked list - Number Does not  exist in the linked list " << endl;
                linkedlist.printAll();
    cout << "Removing Front Element" << endl;
    cout << "Front value of the linked list : " << linkedlist.removeFront() << endl;
    linkedlist.printAll();
    return 0;
}
