#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

node *root = NULL;

node * createTreeNode(int data)
{
    node * newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(int data)
{
    if(root == NULL)
    {
        root = createTreeNode(data);
    }
    else
    {
        node *current = root;
        node *parent = NULL;
        while(current != NULL)
        {
            parent = current;
            if(data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        if(data < parent->data)
        {
            parent->left = createTreeNode(data);
        }
        else
        {
            parent->right = createTreeNode(data);
        }
    }
}

void inOrderTraversal(node *treeNode)
{
    if(treeNode != NULL)
    {
        inOrderTraversal(treeNode->left);
        printf("%d ", treeNode->data);
        inOrderTraversal(treeNode->right);
    }
}

void preOrderTraversal(node *treeNode)
{
    if(treeNode != NULL)
    {
        printf("%d ", treeNode->data);
        preOrderTraversal(treeNode->left);
        preOrderTraversal(treeNode->right);
    }
}

void postOrderTraversal(node *treeNode)
{
    if(treeNode != NULL)
    {
        preOrderTraversal(treeNode->left);
        preOrderTraversal(treeNode->right);
        printf("%d ", treeNode->data);
    }
}

int main(void)
{
    insert(2);
    insert(1);
    insert(4);
    insert(0);
    inOrderTraversal(root);
    printf("\n");
    preOrderTraversal(root);
    printf("\n");
    postOrderTraversal(root);
    printf("\n");
    return 0;
}
