/*SOME ERROR IN DELETE FUNCTION*/

/*  Binary Search Tree(BST) is a binary tree where left child is lesser and right child is greater in value
    when compared to root.  */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    int data;
    struct node *left, *right;
}NODE;

/*GLOBAL VARIABLES*/
//initially the tree is NULL
NODE *root=NULL;

/*FUNCTION PROTOTYPES*/
NODE* createNode(int);

NODE* insertNode(NODE*,int);

NODE* deleteNode(NODE*,int);

NODE* inorderSuccessor(NODE*);

bool searchNode(NODE*,int);

void inorderBST(NODE*);

/*DRIVER CODE*/
void main()
{
    int data1,data2;

    root=insertNode(root,34);
    root=insertNode(root,76);
    root=insertNode(root,25);
    root=insertNode(root,67);
    root=insertNode(root,16);

    printf("\nInorder traversal of BST:\n");
    inorderBST(root);

    printf("\nEnter a node to search:");
    scanf("%d",&data1);
    if(searchNode(root,data1)==true)
    {
        printf("\nNODE found!");
    }
    else
    {
        printf("\nNODE not found!");
    }

    printf("\nEnter a node to delete:");
    scanf("%d",&data2);
    root=deleteNode(root,data2);

    printf("\nInorder traversal of BST:\n");
    inorderBST(root);
}

//The code to create a node
NODE* createNode(int data)
{
    NODE *newnode;
    newnode=(NODE*)malloc(sizeof(NODE));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

//insert a node into the tree
NODE* insertNode(NODE *root,int data)
{
    if(root==NULL)
    {
        root=createNode(data);
        return root;
    }
    else if(data <= root->data)
        {
            root->left=insertNode(root->left,data);
        }
    else
        {
            root->right=insertNode(root->right,data);
        }

        return root;

}

//search a node in BST
bool searchNode(NODE *root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data==data)
    {
        return true;
    }

    else if(data <= root->data)
    {
        return searchNode(root->left,data);
    }
    else
    {
        return searchNode(root->right,data);
    }
}
/*END OF SEARCHING FUNCTION*/



//delete a node from BST
NODE* inorderSuccessor(NODE* root)
{
    /*find the min-valued(left most) node in a tree*/
    NODE* current=root;
    //recursion until the current and its left node exists
    while(current && current->left !=NULL)
    {
        current=current->left;
    }
    return current;
}

NODE* deleteNode(NODE* root,int data)
{
    /*base condition for recursion*/
    if(root==NULL)
    {
        return root;
    }

    //if node to be deleted is smaller or equal to root, move to left subtree
    else if(data<=root->data)
    {
        root->left=deleteNode(root->left,data);
        return root;
    }
    //if node to be deleted is greater than root, move to right subtree
    else if(data>root->data)
    {
        root->right=deleteNode(root->right,data);
    }

    //if the data is same as root data, then move into else and it is the node to be deleted
    else
    {

        /*CASE-1:if the deleted node it leaf node, simply free the node*/
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        /*END OF CASE:1*/

        /* CASE-2: node with one child*/
        else if(root->left==NULL)
        {
            NODE* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            NODE* temp=root->left;
            free(root);
            return temp;
        }
        /*END OF CASE-2*/

        /*CASE-3:node to be deleted has two children*/
        //find the in-order successor (or) in-order predecessor and replace it in deleted node's position

        NODE* temp=inorderSuccessor(root->right);//here we use in-order successor

        root->data=temp->data;//copy in-order successor content to the node

        root->right=deleteNode(root->right,temp->data);//delete the in-order successor
    }
    return root;
}


/*END OF DELETION FUNCTION*/



//in-order traversal of BST.
void inorderBST(NODE *root)
{
    if(root==0)
    {
        return;
    }

        inorderBST(root->left);
        printf("%d,",root->data);
        inorderBST(root->right);

}

