//SELECTION SORT

#include<stdio.h>

/*FUNCTION PROTOTYPES*/
void selectionSort(int[],int);

void main()
{
    int elements;
    printf("---SELECTION SORT---\n");
    int i;
    printf("Enter the total elements in array:");
    scanf("%d",&elements);

    int arr[elements];
    for(i=0;i<elements;i++)
    {
        printf("\nEnter element %d:",i+1);
        scanf("%d",&arr[i]);
    }

    int len=sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr,len);

    printf("\nSorted array:");
    for(i=0;i<elements;i++)
    {
        printf("%d ",arr[i]);
    }
}

/*FUNCTION DEFINITIONS*/

void selectionSort(int arr[],int len)
{
    int i,j;
    int temp,min;
    for(i=0;i<len-1;i++)
    {
        min=i;
        for(j=i+1;j<len;j++)
        {
            if(arr[j] < arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}



