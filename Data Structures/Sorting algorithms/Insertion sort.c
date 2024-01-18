//INSERTION SORT

#include<stdio.h>

/*FUNCTION PROTOTYPES*/
void insertionSort(int[],int);

void main()
{
    int elements;
    printf("---INSERTION SORT---\n");
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

    insertionSort(arr,len);

    printf("\nSorted array:");
    for(i=0;i<elements;i++)
    {
        printf("%d ",arr[i]);
    }
}

/*FUNCTION DEFINITIONS*/

void insertionSort(int arr[],int len)
{
    int i,j;
    int temp;
    for(i=1;i<len;i++)
    {
        temp=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
