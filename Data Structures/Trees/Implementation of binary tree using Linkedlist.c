//Implementation of binary tree using array(recursive approach)

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}NODE;

 NODE *root=0;

NODE* createBTree(void);

void preorder(NODE*);

void inorder(NODE*);

void postorder(NODE*);

void findRoot(void);

int findHeight(NODE*);

void main()
{

     root=createBTree();

     int ch;
     int res=0;
     do
     {
         int menu_ch;

         printf("\n\n------MENU------\n");
         printf("1.Find root\n2.Preorder traversal\n3.inorder traversal\n4.postorder traversal\n5.Find height of tree\n");
         printf("\nEnter your choice to perform operation:");
         scanf("%d",&menu_ch);

         switch(menu_ch)
         {
             case 1:findRoot();
                    break;
             case 2:printf("\nPreorder traversal of Binary tree: ");
                    preorder(root);
                    break;
             case 3:printf("\nInorder traversal of Binary tree: ");
                    inorder(root);
                    break;
             case 4:printf("\nPostorder traversal of Binary tree: ");
                    postorder(root);
                    break;
             case 5:res=findHeight(root);
                    printf("\nHeight of of Binary tree: %d",res);
                    break;
             default:printf("\nWrong choice entered!\n");

         }

         printf("\n\nDo you want to continue?(1/0):");
         scanf("%d",&ch);

     }while(ch==1);


}


NODE* createBTree()
{
    NODE *newnode=0;
    //create the root node
    int n;
    newnode=(NODE*)malloc(sizeof(NODE));
    printf("\nEnter node data(-1 to skip node):");
    scanf("%d",&n);
    //condition for skipping the creation of a child
    if(n==-1)
    {
        return 0;
    }
    newnode->data=n;
    newnode->left=0;
    newnode->right=0;

    //recursive creation of left child
    printf("\nEnter left child of %d",n);
    newnode->left=createBTree();

    //recursive creation of right child
    printf("\nEnter right child of %d",n);
    newnode->right=createBTree();

    return newnode;
}

void findRoot()
{
    printf("\nThe root of the tree is: %d",root->data);
}

//pre-order traversal of binary tree:   <root>  <left>  <right>
void preorder(NODE* root)
{
   if(root==0)
    {
        return ;
    }
    //print(data)   ->call(left)    ->call(right)
    printf("%d,",root->data);
    preorder(root->left);
    preorder(root->right);
}

//in-order traversal of a binary tree:    <left> <root> <right>
void inorder(NODE* root)
{
    if(root==0)
    {
        return;
    }
    //call(left)    ->print(data)   ->call(right)
    inorder(root->left);
    printf("%d,",root->data);
    inorder(root->right);
}

//post order traversal of binary tree:  <left> <right> <root>
void postorder(NODE *root)
{
    if(root==0)
    {
        return;
    }
    //call(right)   ->call(left)    ->print(data)
    postorder(root->left);
    postorder(root->right);
    printf("%d,",root->data);
}

int findHeight(NODE* root)
{
    if(root==NULL)
    {
        return 0;
    }
    int left_height=findHeight(root->left);
    int right_height=findHeight(root->right);
    if(left_height>right_height)
    {
        return left_height+1;
    }
    else
    {
        return right_height+1;
    }
}

