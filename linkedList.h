#ifndef LINKED_LIST
#define LINKED_LIST

class Node
{
public:
    string fileName;
    int location;
    Node *next;
};

class List
{
    Node *head;
    Node *tail;
    Node *temp;
    bool isEmpty()
    {
        return head == NULL;
    }
public:
    List()
    {
        head = NULL;
        tail = NULL;
    }
    
    ~List() {
        delete head;
        delete tail;
        delete temp;
    }

    void insert(int x)
    {
        temp = new Node;
        temp->fileName = x;
        if(isEmpty())
        {
            temp->next = NULL;
            tail = temp;
        }
        else
            temp->next = head;
        head = temp;
    }

    void insertAtEnd(int x)
    {
        temp = new Node;
        temp->fileName = x;
        temp->next = NULL;
        if(isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    void remove(int x)
    {
        temp = head;
        Node *prev;
        while(temp->next != NULL && temp->fileName != x)
        {
            prev = temp;
            temp = temp->next;
        }
        if(temp->fileName == x)
        {
            prev->next = temp->next;
            delete temp;
        }
        else if(temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }

    void find(int x)
    {
        int i;
        for(i=1, temp = head;temp->next != NULL && temp->fileName != x;temp = temp->next, i++);
        if(temp->fileName == x)
        {
            cout << "Found at position:" << i << endl;
        }
        else if(temp->next == NULL)
        {
            cout << "Error: Number Not found..." << endl;
        }
    }

    void display()
    {
        if(!isEmpty())
        {
            for(temp = head; temp != NULL; temp=temp->next)
                cout << temp->fileName << " ";
            cout << endl;
        }
        else
        {
            cout << "List is Empty!" << endl;
        }
    }
};

#endif
