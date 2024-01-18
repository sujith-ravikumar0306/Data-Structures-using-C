#include<stdio.h>

int main()
{
    int i;
    int elements;
    printf("Enter the total elements in array:");
    scanf("%d",&elements);

    int arr[elements];
    for(i=0;i<elements;i++)
    {
        printf("\nEnter element %d:",i+1);
        scanf("%d",&arr[i]);
    }

    int key;
    int index;
    int flag=0;
    printf("\nEnter a key to search:");
    scanf("%d",&key);

    for(i=0;i<elements;i++)
    {
        if(arr[i]==key)
        {
            index=i;
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf("\nElement not found!");
    }
    else
    {
        printf("\nThe element is found at index:%d",index);
    }
}
