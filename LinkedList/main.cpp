#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int new_value)
{
    Node *new_node = new Node();
    new_node->data = new_value;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void insertAt(Node *prev_node, int new_value)
{
    if (prev_node == NULL)
    {
        cout << "Prev Node seems to be NULL";
        return;
    }
    Node *new_node = new Node();
    new_node->data = new_value;

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(Node **head_ref, int new_value)
{
    Node *new_node = new Node();
    new_node->data = new_value;

    Node *last = *head_ref;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void printlist(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data;
        node = node->next;
    }
}

void deleteNode(Node **head_ref, int key)
{
    Node *temp = *head_ref, *prev;

    //case 1
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    //case 2
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    //case 3
    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}

void deleteentirelist(Node **head_ref)
{
    Node *current = *head_ref;
    Node *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}

int getCount(Node *head)
{
    int count = 0;
    Node *current = head;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void reverseList(Node *node)
{
    Node *current = node;
    Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
    }

    node = prev; //head = prev;
}

int main()
{
    Node *head = NULL;

    append(&head, 4);
    push(&head, 5);
    printlist(head);
    return 0;
}