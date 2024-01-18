//QUICK SELECT ALGORITHM:-
//This algorithm is used to find the k-th smallest element in a list
//Unlike quick sort, the algorithm is recursively applied only on part of list that contains the solution

#include<stdio.h>

//GLOBAL DECLARATIONS

int i=0,j=0;

//FUNCTION PROTOTYPES

void swap(int*, int*);

int partition(int[],int,int);

int quickSelect(int[], int, int, int);

void main()
{
    int len;
    printf("Enter the total elements in list:");
    scanf("%d",&len);

    int arr[len];
    for(i=0;i<len;i++)
    {
        printf("\nEnter element %d :",i+1);
        scanf("%d",&arr[i]);
    }
    int left=0;
    int right=len-1;
    int k;
    printf("\nEnter the value of k to find k^th smallest element:");
    scanf("%d",&k);

    int res=quickSelect(arr,left,right,k);

    if(res!=-1)
    {
        printf("\nThe %dth smallest element is %d",k,res);
    }
    else
    {
        printf("\nInvalid value of k!");
    }
}


//FUNCTION DEFINITIONS

void swap(int *x, int  *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int partition(int arr[], int low, int high)
{
    //last element is taken as pivot
    int pivot= arr[high];
    //left is set to starting position of sub-array
    i= low;

    for(j=low;j<high;j++)
    {
        //if element < pivot (swap elements)
        if(arr[j]<pivot)
        {
            swap(&arr[i],&arr[j]);
            i++;
        }
    }
    //finally swap the pivot with i
    swap(&arr[i],&arr[high]);
    return i;
}

int quickSelect(int arr[], int low, int high, int k)
{

    while(low<=high)
    {
        int pivot=partition(arr,low,high);

        if(pivot == k-1)
        {
            return arr[pivot];
        }
        else if(pivot  > k-1)
        {
            high= pivot-1;
        }
        else
        {
            low= pivot+1;
        }
    }

    return -1;  // when k is out of range
}
