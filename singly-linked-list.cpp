//
//  main.cpp
//  DSA
//
//  Created by Anurag Gupta on 16/08/20.
//  Copyright © 2020 Anurag Gupta. All rights reserved.
//

#include <iostream>
#define ll long long int
using namespace std;

class Node
{
public:
    int key;
    int data;
    Node *next;
    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    Node(int k, int d)
    {
        key = k;
        data = d;
    }
};

class SinglyLinkedList
{
public:
    Node *head;

    SinglyLinkedList()
    {
        head = NULL;
    }
    SinglyLinkedList(Node *n)
    {
        head = n;
    }

    //Check if node exist using key value
    Node *nodeExist(int k)
    {
        Node *temp = NULL;
        Node *ptr = head;

        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }

    //Append node
    void appendNode(Node *n)
    {
        if (nodeExist(n->key) == NULL)
        {
            if (head == NULL)
            {
                head = n;
            }
            else
            {
                Node *ptr = head;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
            }
            cout << "Node Appended" << endl;
        }
        else
        {
            cout << "Key error" << endl;
        }
    }

    //Prepend Node
    void prependNode(Node *n)
    {
        if (nodeExist(n->key) == NULL)
        {
            n->next = head;
            head = n;
            cout << "Node Prepended" << endl;
        }
        else
        {
            cout << "Key error" << endl;
        }
    }

    //Insert Node after particular key
    void insertNode(int k, Node *n)
    {
        Node *ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "No Node exist" << endl;
        }
        else
        {
            if (nodeExist(n->key) == NULL)
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node Inserted" << endl;
            }
            else
            {
                cout << "Key error" << endl;
            }
        }
    }

    //Delete Node By Key
    void deleteNodeByKey(int k)
    {
        if (head == NULL)
        {
            cout << "Linked List is empty." << endl;
        }
        else if (head != NULL)
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Node Unlinked" << endl;
            }
            else
            {
                Node *temp = NULL;
                Node *currptr = head->next;
                Node *preptr = head;
                while (currptr != NULL)
                {
                    if (currptr->key == k)
                    {
                        temp = currptr;
                        currptr = NULL;
                    }
                    else
                    {
                        currptr = currptr->next;
                        preptr = preptr->next;
                    }
                }
                if (temp != NULL)
                {
                    preptr->next = temp->next;
                    cout << "Node Unlinked" << endl;
                }
                else
                {
                    cout << "Node doesn't exist" << endl;
                }
            }
        }
    }

    //Update Node By Key
    void updateNode(int k, int d)
    {
        Node *ptr = nodeExist(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Updated" << endl;
        }
        else
        {
            cout << "Node doesn't exist" << endl;
        }
    }

    //Printing
    void printList()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty" << endl;
        }
        else
        {
            cout << "Values:-" << endl;
            Node *temp = head;
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->data << "," << temp->next << ")" << endl;
                temp = temp->next;
            }
        }
    }
};

int main()
{
    SinglyLinkedList s;
    int option;
    int key1, k1, data1;
    do
    {
        cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
        cout << "1. appendNode()" << endl;
        cout << "2. prependNode()" << endl;
        cout << "3. insertNodeAfter()" << endl;
        cout << "4. deleteNodeByKey()" << endl;
        cout << "5. updateNodeByKey()" << endl;
        cout << "6. print()" << endl
             << endl;

        cin >> option;
        Node *n1 = new Node();
        //Node n1;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            //cout<<n1.key<<" = "<<n1.data<<endl;
            break;

        case 2:
            cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            break;

        case 3:
            cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
            cin >> k1;
            cout << "Enter key & data of the New Node first: " << endl;
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;

            s.insertNode(k1, n1);
            break;

        case 4:

            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            s.deleteNodeByKey(k1);

            break;
        case 5:
            cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
            cin >> key1;
            cin >> data1;
            s.updateNode(key1, data1);

            break;
        case 6:
            s.printList();

            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
