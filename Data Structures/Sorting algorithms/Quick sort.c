//QUICK SORT

#include<stdio.h>

/*FUNCTION PROTOTYPES*/
void quickSort(int[], int, int);

int partition(int[], int, int);

void main()
{
    int elements;
    printf("---QUICK SORT---\n");
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
    printf("\nlen=%d",len);

    int lb=0,ub=len-1;
    printf("\nub=%d",ub);
    printf("\nlb=%d",lb);

    quickSort(arr,lb,ub);

    printf("\nSorted array:");
    for(i=0;i<elements;i++)
    {
        printf("%d ",arr[i]);
    }
}

/*FUNCTION DECLARATIONS*/

void quickSort(int arr[],int lb, int ub)
{
    if(lb<ub)
    {
        int location=partition(arr,lb,ub);
        quickSort(arr,lb,location-1);
        quickSort(arr,location+1,ub);
    }
}


int partition(int arr[],int lb,int ub)
{
    int temp;
    int pivot=arr[lb];
    int start=lb;
    int end=ub;

    //valid pass
    while(start<end)
    {
        //when element is greater than pivot stop incrementing start
        while(arr[start]<=pivot)
        {
            start++;
        }
        //when element is less than pivot stop decrementing end
        while(arr[end]>pivot)
        {
            end--;
        }

        //if start index is less than that of end index, swap the elements in start and end index
        if(start<end)
        {
            temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
        }
    }
    //swap the lower bound(pivot) with end when start index > end index
    temp=arr[lb];
    arr[lb]=arr[end];
    arr[end]=temp;

    //this end position will be used to perform sorting on left sub-array(lb to end-1) and right sub-array (end+1 to up);
    return end;
}

