#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node
{
    int data;
    struct node *left,*right;
};

//create a node
struct node* create(int data)
{
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->right=newnode->left=NULL;

    return newnode;
}

//insert a node
struct node* insert(struct node* root, int data)
{
    if(root==NULL)
    {
        return create(data);
    }
    else if(data > root->data)
    {
        root->right=insert(root->right,data);
        return root;
    }
    else
    {
        root->left=insert(root->left,data);
        return root;
    }

}

//inorder traversal
struct node* inorderBST(struct node* root)
{
    if(root==NULL)
    {
        return 0;
    }
        inorderBST(root->left);
        printf("%d ",root->data);
        inorderBST(root->right);
}

//searching a node in BST
bool search(struct node* root,int data)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data == data)
    {
        return true;
    }
    else if(data > root->data)
    {
        return search(root->right,data);
    }
    else
    {
        return search(root->left,data);
    }
}


//finding the inorder successor
struct node* inorderSuccessor(struct node* node)
{
    struct node* curr=node;
    while(curr && curr->left != NULL)
        curr=curr->left;

    return curr;
}


//deleting a node
struct node* del(struct node* root, int data)
{
    //base condition
    if(root==NULL)return root;

    //find node to be deleted
    if(data > root->data)
    {
        root->right=del(root->right,data);
    }
    else if(data <= root->data)
    {
        root->left=del(root->left,data);
    }

    else
    {
        if(root->left==NULL)
        {
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node* temp=root->left;
            free(root);
            return temp;
        }

        struct node* temp=inorderSuccessor(root->right);
        root->data=temp->data;
        root->right=del(root->right,temp->data);
    }
return root;

}

void main()
{
    struct node* root=NULL;
    int data;

    printf("Inserting nodes...");
    root=insert(root,10);
    root=insert(root,50);
    root=insert(root,40);
    root=insert(root,90);
    root=insert(root,70);
    root=insert(root,0);


    printf("\nInorder traversal:\n");
    inorderBST(root);

    printf("\nSearching function:");
    printf("\nEnter a node to search:");
    scanf("%d",&data);

    if( search(root,data) == true)
    {
        printf("node found!");
    }
    else
    {
        printf("node not found!");
    }

    printf("\nDeleting a node:40");
    root=del(root,40);

    printf("\nInorder traversal:\n");
    inorderBST(root);

}
