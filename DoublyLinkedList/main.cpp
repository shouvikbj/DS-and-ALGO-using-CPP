#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if (*head_ref != NULL)
    {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;
}

void insertAfter(Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        cout << "prev node cannot be null";
        return;
    }

    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if (new_node->next != NULL)
    {
        new_node->next->prev = new_node;
    }
}

void addtoend(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    Node *last = *head_ref;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    return;
}

void deleteNode(Node **head_ref, Node *key)
{
    if (*head_ref == NULL || key == NULL)
    {
        return;
    }

    // case 1
    if (*head_ref == key)
    {
        *head_ref = key->next;
    }

    //case 2
    if (key->next != NULL)
    {
        key->next->prev = key->prev;
    }
    //case 3
    if (key->prev != NULL)
    {
        key->prev->next = key->next;
    }

    free(key);
    return;
}

void printdlist(Node *node)
{
    while (node != NULL)
    {
        cout << " " << node->data << " ";
        node = node->next;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
