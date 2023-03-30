#include <iostream>
using namespace std;

struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, int data)
{
    if (node == NULL)
    {
        return newNode(data);
    }
    if (data < node->key)
    {
        node->left = insert(node->left, data);
    }
    else
    {
        node->right = insert(node->right, data);
    }
}

struct node *inorder_successor(struct node *node)
{
    struct node *newval = node;
    while (newval->left != NULL)
    {
        newval = newval->left;
    }
    return newval;
}

struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->key)
        root->left = deleteNode(root->left, data);
    else if (data > root->key)
    {
        root->right = deleteNode(root->right, data);
    }

    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = inorder_successor(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d", root->key);
        inorder(root->right);
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d", root->key);
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
