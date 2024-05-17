#ifndef FUNCTIONS_H
#define FUNCTIONS_H 
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

//Tree create node
node *createTreeNode(int data);

//Tree insert 
void insert(int data);

//Tree traversals
void inOrderTraversal(node *treeNode);
void preOrderTraversal(node *treeNode);
void postOrderTraversal(node *treeNode);

#endif // FUNCTIONS_H
