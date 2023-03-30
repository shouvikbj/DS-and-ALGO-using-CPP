#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void push(Node **head_ref, int data)
{
    Node *new_node = new Node();
    Node *tmp = *head_ref;
    new_node->data = data;
    new_node->next = *head_ref;

    if (*head_ref != NULL)
    {
        while (tmp->next != *head_ref)
        {
            tmp = tmp->next;
        }
        tmp->next = new_node;
    }
    else
        new_node->next = new_node;

    *head_ref = new_node;
}

void deleteNode(Node **head, int key)
{

    //if linked list is empty
    if (*head == NULL)
        return;

    //head is the only element
    if ((*head)->data == key && (*head)->next == *head)
    {
        free(*head);
        *head = NULL;
    }

    Node *last = *head, *d;

    //head but many elements
    if ((*head)->data == key)
    {
        while (last->next != *head)
        {
            last = last->next;
        }
        last->next = (*head)->next;
        free(*head);
        *head = last->next;
    }

    while (last->next != *head && last->next->data != key)
    {
        last = last->next;
    }

    //node to be deleted
    if (last->next->data == key)
    {
        d = last->next;
        last->next = d->next;
        free(d);
    }

    //node is not found
    else
        cout << "value not found";
}
////////////
Node *tocircular(Node *head)
{
    Node *start = head;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->next = start;
    return start;
}

int countnodes(Node *head)
{
    if (head == NULL)
    {
        return 0;
    }

    int count = 0;
    Node *current = head;

    do
    {
        count++;
        current = current->next;
    } while (current != head);

    return count;
}

void cprintlist(Node *head)
{
    Node *temp = head;
    if (head != NULL)
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    push(&head, 30);
    push(&head, 20);
    push(&head, 25);
    cprintlist(head);
    return 0;
}
